/**
 * T License (MIT)
 *
 * Copyright (c) 2018 Distributed Systems Group, University of Kassel, Germany
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "model/Model.h"
#include "model/Wumpus.h"
#include "model/Agent.h"
#include "model/GroundTile.h"

#include <QJsonObject>
#include <QJsonArray>

#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <memory>

namespace wumpus_simulator
{

	Model* Model::get()
	{
		static Model instance;
		return &instance;
	}

	void Model::init(bool agentHasArrow, int wumpusCount, int trapCount, int playGroundSize)
	{
		this->playGround.clear();
		this->agentHasArrow = agentHasArrow;
		this->playGroundSize = playGroundSize;
		this->trapCount = trapCount;
		this->wumpusCount = wumpusCount;
		for (int i = 0; i < this->playGroundSize; i++)
		{
			this->playGround.push_back(std::vector<std::shared_ptr<GroundTile>>());
		}
		for (int i = 0; i < this->playGroundSize; i++)
		{
			for (int j = 0; j < this->playGroundSize; j++)
			{
				this->playGround.at(i).push_back(std::make_shared<GroundTile>(i, j));
			}
		}
		std::cout << "Tiles created" << std::endl;
		// initialize random seed:
		srand(time(NULL));
		// Place given number of traps on field
		for (int i = 0; i < trapCount; i++)
		{
			int randx = rand() % (this->playGroundSize - 1);
			int randy = rand() % (this->playGroundSize - 1);

			if (!playGround.at(randx).at(randy)->getTrap())
			{
				playGround.at(randx).at(randy)->setTrap(true);
				setBreeze(randx, randy);
			}
			else
			{
				i--;
			}
		}
		std::cout << "Traps created" << std::endl;
		// Place Wumpus on field
		for (int i = 0; i < wumpusCount; i++)
		{
			int randx = rand() % (this->playGroundSize - 1);
			int randy = rand() % (this->playGroundSize - 1);

			if (playGround.at(randx).at(randy)->getTrap() || playGround.at(randx).at(randy)->hasMovable())
			{
				i--;
			}
			else
			{
				auto tmp = std::make_shared<Wumpus>(playGround.at(randx).at(randy));
				playGround.at(randx).at(randy)->setMovable(tmp);
				setStench(randx, randy);
				this->movables.push_back(tmp);
			}

		}
		std::cout << "Wumpus created" << std::endl;

		// Place Gold on field
		bool placed = false;
		while (!placed)
		{
			int randx = rand() % (this->playGroundSize - 1);
			int randy = rand() % (this->playGroundSize - 1);

			if (!(playGround.at(randx).at(randy)->getTrap() || playGround.at(randx).at(randy)->hasMovable()))
			{
				playGround.at(randx).at(randy)->setGold(true);
				placed = true;
			}
		}
		std::cout << "Gold placed" << std::endl;
		for (int i = 0; i < this->playGround.size(); i++)
		{
			for (int j = 0; j < this->playGround.size(); j++)
			{
				if (this->playGround.at(i).at(j)->hasMovable() || this->playGround.at(i).at(j)->getTrap())
				{
					this->playGround.at(i).at(j)->setBreeze(false);
					this->playGround.at(i).at(j)->setStench(false);
				}
			}
		}
		std::cout << "Model: Finished initiating the playground!" << std::endl;
	}

	Model::Model()
	{
		rosNode = new ros::NodeHandle();
		this->agentHasArrow = false;
		this->playGroundSize = -1;
		this->trapCount = -1;
		this->wumpusCount = -1;

	}

	Model::~Model()
	{
	}

	void Model::setBreeze(int x, int y)
	{
		if (x == 0)
		{
			playGround.at(x + 1).at(y)->setBreeze(true);

		}
		else if (x == playGroundSize - 1)
		{
			playGround.at(x - 1).at(y)->setBreeze(true);

		}
		else
		{
			playGround.at(x - 1).at(y)->setBreeze(true);
			playGround.at(x + 1).at(y)->setBreeze(true);
		}

		if (y > 0)
		{
			playGround.at(x).at(y - 1)->setBreeze(true);
		}

		if (y < playGroundSize - 1)
		{
			playGround.at(x).at(y + 1)->setBreeze(true);
		}
	}

	bool Model::getAgentHasArrow()
	{
		return agentHasArrow;
	}

	int Model::getPlayGroundSize()
	{
		return playGroundSize;
	}

	int Model::getTrapCount()
	{
		return trapCount;
	}

	int Model::getWumpusCount()
	{
		return wumpusCount;
	}

	std::vector<std::vector<std::shared_ptr<GroundTile>>> Model::getPlayGround()
	{
		return playGround;
	}

	void Model::exit(std::shared_ptr<Agent> agent)
	{
		this->movables.erase(remove(this->movables.begin(), this->movables.end(), agent), this->movables.end());
		agent->getTile()->setMovable(nullptr);
		agent->setTile(nullptr);
		for (auto tileVec : this->playGround)
		{
			for (auto tile : tileVec)
			{
				if (tile->getStartAgentID() == agent->getId())
				{
					tile->setStartAgentID(0);
					tile->setStartpoint(false);
					break;
				}
			}
		}
	}

	void Model::setStench(int x, int y)
	{
		if (x == 0)
		{
			if (!playGround.at(x + 1).at(y)->hasWumpus())
			{
				playGround.at(x + 1).at(y)->setStench(true);
			}

		}
		else if (x == playGroundSize - 1)
		{
			if (!playGround.at(x - 1).at(y)->hasWumpus())
			{
				playGround.at(x - 1).at(y)->setStench(true);
			}

		}
		else
		{
			if (!playGround.at(x - 1).at(y)->hasWumpus())
			{
				playGround.at(x - 1).at(y)->setStench(true);
			}
			if (!playGround.at(x + 1).at(y)->hasWumpus())
			{
				playGround.at(x + 1).at(y)->setStench(true);
			}

		}

		if (y > 0)
		{
			if (!playGround.at(x).at(y - 1)->hasWumpus())
			{
				playGround.at(x).at(y - 1)->setStench(true);
			}
		}

		if (y < playGroundSize - 1)
		{
			if (!playGround.at(x).at(y + 1)->hasWumpus())
			{
				playGround.at(x).at(y + 1)->setStench(true);
			}
		}
	}

	std::shared_ptr<GroundTile> Model::getTile(int x, int y)
	{
		return this->playGround.at(x).at(y);
	}

	QJsonObject Model::toJSON()
	{
		//Root JSON object
		QJsonObject world;

		//Add attributes of the world like size and so on
		world["playGroundSize"] = playGroundSize;
		world["wumpusCount"] = wumpusCount;
		world["trapCount"] = trapCount;
		world["agentHasArrow"] = agentHasArrow;

		//JSON Array to hold the playground
		QJsonArray playground;
		for (int i = 0; i < playGroundSize; i++)
		{

			for (int j = 0; j < playGroundSize; j++)
			{

				QJsonObject ground;
				ground["x"] = playGround.at(i).at(j)->getX();
				ground["y"] = playGround.at(i).at(j)->getY();
				ground["hasTrap"] = playGround.at(i).at(j)->getTrap();
				ground["hasGold"] = playGround.at(i).at(j)->getGold();
				ground["hasStench"] = playGround.at(i).at(j)->getStench();
				ground["hasBreeze"] = playGround.at(i).at(j)->getBreeze();
				ground["isStartpoint"] = playGround.at(i).at(j)->getStartpoint();
				ground["startAgentID"] = playGround.at(i).at(j)->getStartAgentID();
				if (playGround.at(i).at(j)->getMovable() != nullptr)
				{
					ground["movableType"] = playGround.at(i).at(j)->getMovable()->getType();
					auto tmp = std::dynamic_pointer_cast<Agent>(playGround.at(i).at(j)->getMovable());
					if (tmp != nullptr)
					{
						ground["agentHeading"] = tmp->getHeading();
						ground["agentId"] = tmp->getId();
						ground["agentHasGold"] = tmp->getHasGold();
						ground["agentHasArrow"] = tmp->hasArrow();
					}
					else
					{
						ground["agentHeading"] = "unknown";
						ground["agantId"] = 0;
					}
				}
				else
				{
					ground["movableType"] = "unknown";
					ground["agentHeading"] = "unknown";
					ground["agentId"] = 0;
				}

				playground.append(ground);

			}
		}

		world["playground"] = playground;

		return world;

	}

	void Model::fromJSON(QJsonObject root)
	{

		//Clear the old vectors
		this->playGround.clear();
		this->movables.clear();
		//Reset global variables
		this->agentHasArrow = root["agentHasArrow"].toBool();
		this->playGroundSize = root["playGroundSize"].toInt();
		this->trapCount = root["trapCount"].toInt();
		this->wumpusCount = root["wumpusCount"].toInt();
		// Init the playground
		for (int i = 0; i < this->playGroundSize; i++)
		{
			this->playGround.push_back(std::vector<std::shared_ptr<GroundTile>>());
		}
		for (int i = 0; i < this->playGroundSize; i++)
		{
			for (int j = 0; j < this->playGroundSize; j++)
			{
				this->playGround.at(i).push_back(std::make_shared<GroundTile>(i, j));
			}
		}
		//Load the playground
		QJsonArray tiles = root["playground"].toArray();
		for (int i = 0; i < tiles.size(); i++)
		{
			QJsonObject tile = tiles[i].toObject();
			auto x = tile["x"].toInt();
			auto y = tile["y"].toInt();
			auto groundTile = this->playGround.at(x).at(y);
			groundTile->setBreeze(tile["hasBreeze"].toBool());
			groundTile->setGold(tile["hasGold"].toBool());
			groundTile->setStench(tile["hasStench"].toBool());
			groundTile->setStartAgentID(tile["startAgentID"].toInt());
			groundTile->setStartpoint(tile["isStartpoint"].toBool());
			groundTile->setTrap(tile["hasTrap"].toBool());
			if (tile["movableType"].toString().contains("wumpus"))
			{
				auto wumpus = std::make_shared<Wumpus>(this->playGround.at(x).at(y));
				this->movables.push_back(wumpus);
				groundTile->setMovable(wumpus);
			}
			else if (tile["movableType"].toString().contains("agent"))
			{
				auto agent = std::make_shared<Agent>(this->playGround.at(x).at(y));
				agent->setHeading((WumpusEnums::heading)tile["agentHeading"].toInt());
				agent->setId(tile["agentId"].toInt());
				agent->setHasGold(tile["agentHasGold"].toBool());
				agent->setArrow(tile["agentHasArrow"].toBool());
				this->movables.push_back(agent);
				groundTile->setMovable(agent);
			}

		}
	}

	std::shared_ptr<Agent> Model::getAgentByID(int id)
	{

		for (auto mov : this->movables)
		{

			if (mov->getId() == id)
			{
				return std::dynamic_pointer_cast<Agent>(mov);

			}
		}
		return nullptr;
	}

	std::shared_ptr<Wumpus> Model::getWumpusByID(int id)
	{

		for (auto mov : this->movables)
		{

			if (mov->getId() == id)
			{
				return std::dynamic_pointer_cast<Wumpus>(mov);

			}
		}
		return nullptr;
	}

	void Model::removeAgent(std::shared_ptr<Agent> agent)
	{
		agent->getTile()->setMovable(nullptr);
		agent->setTile(nullptr);
	}

	void Model::removeWumpus(std::shared_ptr<Wumpus> wumpus)
	{
		int x = wumpus->getTile()->getX();
		int y = wumpus->getTile()->getY();
		if (x == 0)
		{
			playGround.at(x + 1).at(y)->setStench(false);

		}
		else if (x == playGroundSize - 1)
		{
			playGround.at(x - 1).at(y)->setStench(false);

		}
		else
		{
			playGround.at(x - 1).at(y)->setStench(false);
			playGround.at(x + 1).at(y)->setStench(false);
		}

		if (y > 0)
		{
			playGround.at(x).at(y - 1)->setStench(false);
		}

		if (y < playGroundSize - 1)
		{
			playGround.at(x).at(y + 1)->setStench(false);
		}
		wumpus->getTile()->setMovable(nullptr);
	}

} /* namespace wumpus_simulator */
