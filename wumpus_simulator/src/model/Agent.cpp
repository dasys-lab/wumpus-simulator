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

#include <model/Agent.h>

namespace wumpus_simulator
{

	Agent::Agent(std::shared_ptr<GroundTile> tile)
	{
		this->tile = tile;
		type = "agent";
		arrow = false;
		hasGold = false;
		this->heading = WumpusEnums::heading::up;
	}

	Agent::~Agent()
	{
	}

	bool Agent::hasArrow()
	{
		return arrow;
	}

	void Agent::setArrow(bool value)
	{
		this->arrow = value;
	}

	WumpusEnums::heading Agent::getHeading()
	{
		return heading;
	}

	void Agent::setHeading(WumpusEnums::heading heading)
	{
		this->heading = heading;
	}

	void wumpus_simulator::Agent::setHasGold(bool value)
	{
		this->hasGold = value;
	}

	bool wumpus_simulator::Agent::getHasGold()
	{
		return hasGold;
	}


} /* namespace wumpus_simulator */

