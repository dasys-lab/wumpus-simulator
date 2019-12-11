#include "generator/FileHandler.h"
#include <SystemConfig.h>
#include <iostream>
#include <model/Model.h>
#include <model/Wumpus.h>
#include <model/Movable.h>
#include <model/GroundTile.h>
#include <ros/ros.h>

// generate a specific model - TODO use system config or other means to specify models
int main(int argc, char* argv[])
{
    // needed for node in wumpus simulator model
    ros::init(argc, argv, essentials::SystemConfig::getInstance()->getHostname() + "_wwfgen_specific");

    // program desired model
    wumpus_simulator::Model* model = wumpus_simulator::Model::get();
    int playgroundSize = 6;
    // create dummy model
    model->init(true, 4, 1, playgroundSize);
    // remove randomly placed gold
    for (int i = 0; i < model->getPlayGroundSize(); ++i) {
        for (int j = 0; j < model->getPlayGroundSize(); ++j) {
            auto t = model->getPlayGround().at(i).at(j);
            t->setGold(false);
            auto movables = t->getMovables();
            for(auto mov :movables) {
                t->removeMovable(mov); //FIXME not going to work
                std::cout << "WWFGen main: fix removal of movables " << std::endl;
            }
//            t->setMovable(nullptr);
            t->setTrap(false);
            t->setTrap(false);
            t->setBreeze(false);
            t->setStench(false);
        }
    }

    //GOLD
    std::shared_ptr<wumpus_simulator::GroundTile> tile;
    tile = model->getTile(3, 2);
    tile->setGold(true);

//    //WUMPI
    std::shared_ptr<wumpus_simulator::Wumpus> wumpus;
    tile = model->getTile(1, 0);
    wumpus = std::make_shared<wumpus_simulator::Wumpus>(tile);
    tile->addMovable(std::dynamic_pointer_cast<wumpus_simulator::Movable>(wumpus));
    model->setStench(1,0);
//
    tile = model->getTile(2, 3);
    wumpus = std::make_shared<wumpus_simulator::Wumpus>(tile);
    tile->addMovable(std::dynamic_pointer_cast<wumpus_simulator::Movable>(wumpus));
    model->setStench(2,3);

    tile = model->getTile(4, 3);
    wumpus = std::make_shared<wumpus_simulator::Wumpus>(tile);
    tile->addMovable(std::dynamic_pointer_cast<wumpus_simulator::Movable>(wumpus));
    model->setStench(4,3);

    tile = model->getTile(4, 4);
    wumpus = std::make_shared<wumpus_simulator::Wumpus>(tile);
    tile->addMovable(std::dynamic_pointer_cast<wumpus_simulator::Movable>(wumpus));
    model->setStench(4,4);

    //TRAPS
    tile = model->getTile(3, 3);
    tile->setTrap(true);
    model->setBreeze(3,3);

    generator::FileHandler fh(model);
    fh.extractFilename(false);
    fh.saveWWFile();
}