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

#include "GroundTile.h"
#include "Movable.h"

#include <qdebug.h>
#include <ros/ros.h>

#include <memory>
#include <vector>

namespace wumpus_simulator
{

class Wumpus;
class Agent;

/**
 * Encapsulates all necessary information for current simulation.
 */
class Model
{
public:
    /**
     * Returns model singleton
     * @return Model*
     */
    static Model* get();
    virtual ~Model();
    /**
     * Creates a new model and initializes it with the given values.
     * @param agentHasArrow bool Determines if the agents can shoot an arrow
     * @param wumpusCount int the number of wumpus that will be spawned
     * @param trapCount int the number of traps that will be spawned
     * @param playGroundSize int edge length of square field
     */
    void init(bool agentHasArrow, int wumpusCount, int trapCount, int playGroundSize);

    /**
     * Returns the tile located at x and y
     * @return shared_ptr<GroundTile>
     */
    std::shared_ptr<GroundTile> getTile(int x, int y);

    // Getters
    bool getAgentHasArrow();
    int getPlayGroundSize();
    int getTrapCount();
    int getWumpusCount();
    std::vector<std::vector<std::shared_ptr<GroundTile>>> getPlayGround();

    /**
     * A vector of all wumpus and agents
     */
    std::vector<std::shared_ptr<Movable>> movables;

    /**
     * Returns the agent with the given ID. Returns null if not found.
     */
    std::shared_ptr<Agent> getAgentByID(int id);

    /**
     * Returns the wumpus with the given ID. Returns null if not found.
     */
    std::shared_ptr<Wumpus> getWumpusByID(int id);

    /**
     * Serializes the complete model to a QJsoinObject
     */
    QJsonObject toJSON();

    /**
     * Create a new model from a given QJsonObject.
     */
    void fromJSON(QJsonObject root);

    /**
     * Removes only the visual representation of given agent
     */
    void removeAgent(std::shared_ptr<Agent> agent);

    /**
     * Completely removes given agent from model
     */
    void exit(std::shared_ptr<Agent> agent);

    /**
     * Removes only the visual representation of given wumpus
     */
    void removeWumpus(std::shared_ptr<Wumpus> wumpus);

    /**
     * Sets stench at given coordinates
     */
    void setStench(int x, int y);
    /**
     * Sets breeze at given coordinates
     */
    void setBreeze(int x, int y);

private:
    ros::NodeHandle* rosNode;
    int playGroundSize;
    int wumpusCount;
    int trapCount;
    bool agentHasArrow;
    std::vector<std::vector<std::shared_ptr<GroundTile>>> playGround;

    Model();
};

} /* namespace wumpus_simulator */
