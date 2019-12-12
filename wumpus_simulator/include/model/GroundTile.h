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

#pragma once

#include <memory>
#include <vector>

namespace wumpus_simulator
{
	class Movable;
	class Agent;
	class Wumpus;
	/**
	 * Basic element of the field
	 */
	class GroundTile
	{

	public:
		GroundTile(int x, int y);
		virtual ~GroundTile();
		int getX();
		int getY();
		void setStartAgentID(int value);
		void setStartpoint(bool value);
		void setTrap(bool value);
		void setStench(bool value);
		void setGold(bool value);
		std::vector<std::shared_ptr<Movable>> getMovables();
		void addMovable(std::shared_ptr<Movable> movable);
		void removeMovable(std::shared_ptr<Movable> movable);
		void setBreeze(bool hasBreeze);

		std::vector<std::shared_ptr<Wumpus>> getWumpi();
		std::vector<std::shared_ptr<Agent>> getAgents();

		int getStartAgentID();
		bool getTrap();
		bool getGold();
		bool getStench();
		bool hasMovable();
		bool getBreeze();
		bool getStartpoint();
		bool hasWumpus();


	private :
		int x;
		int y;
		int startAgentID;
		bool hasTrap;
		bool hasGold;
		bool hasStench;
		bool hasBreeze;
		bool isStartpoint;
		std::vector<std::shared_ptr<Agent>> agents;
		std::vector<std::shared_ptr<Wumpus>> wumpi;
		std::vector<std::shared_ptr<Movable>> movables;
	};

} /* namespace wumpus_simulator */
