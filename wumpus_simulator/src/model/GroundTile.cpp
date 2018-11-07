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

#include "model/GroundTile.h"
#include "model/Wumpus.h"

namespace wumpus_simulator
{

GroundTile::GroundTile(int x, int y)
{
    this->x = x;
    this->y = y;
    this->startAgentID = 0;
    this->hasGold = false;
    this->hasTrap = false;
    this->hasStench = false;
    this->hasBreeze = false;
    this->isStartpoint = false;
    this->movable = nullptr;
}

GroundTile::~GroundTile() {}

int GroundTile::getX()
{
    return x;
}

int GroundTile::getY()
{
    return y;
}

bool GroundTile::getGold()
{
    return hasGold;
}

bool GroundTile::getStench()
{
    return hasStench;
}

bool GroundTile::getTrap()
{
    return hasTrap;
}

int GroundTile::getStartAgentID()
{
    return startAgentID;
}

void GroundTile::setStartAgentID(int value)
{
    startAgentID = value;
}

void GroundTile::setStartpoint(bool value)
{
    isStartpoint = value;
}

bool GroundTile::getStartpoint()
{
    return isStartpoint;
}

void GroundTile::setGold(bool value)
{
    hasGold = value;
}

void GroundTile::setTrap(bool value)
{
    hasTrap = value;
}

void GroundTile::setStench(bool value)
{
    hasStench = value;
}

bool GroundTile::hasMovable()
{
    if (movable != nullptr) {
        return true;
    } else {
        return false;
    }
}

std::shared_ptr<Movable> GroundTile::getMovable()
{
    return movable;
}

void GroundTile::setMovable(std::shared_ptr<Movable> movable)
{
    this->movable = movable;
}

bool GroundTile::getBreeze()
{
    return hasBreeze;
}

void GroundTile::setBreeze(bool hasBreeze)
{
    this->hasBreeze = hasBreeze;
}

bool GroundTile::hasWumpus()
{
    if (!this->hasMovable()) {
        return false;
    } else {
        return std::dynamic_pointer_cast<Wumpus>(this->movable) != nullptr;
    }
}

} /* namespace wumpus_simulator */
