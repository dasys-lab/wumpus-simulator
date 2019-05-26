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
    int playgroundSize = 4;
    // create dummy model
    model->init(true, 0, 3, playgroundSize);
    // remove randomly placed gold
    for (int i = 0; i < model->getPlayGroundSize(); ++i) {
        for (int j = 0; j < model->getPlayGroundSize(); ++j) {
            auto t = model->getPlayGround().at(i).at(j);
            t->setGold(false);
            t->setMovable(nullptr);
            t->setTrap(false);
            t->setBreeze(false);
        }
    }

    //GOLD
    std::shared_ptr<wumpus_simulator::GroundTile> tile;
    tile = model->getTile(0, 1);
    tile->setGold(true);

//    //WUMPI
//    std::shared_ptr<wumpus_simulator::Wumpus> wumpus;
//    tile = model->getTile(1, 0);
//    wumpus = std::make_shared<wumpus_simulator::Wumpus>(tile);
//    tile->setMovable(std::dynamic_pointer_cast<wumpus_simulator::Movable>(wumpus));
//    model->setStench(1,0);
//
//    tile = model->getTile(0, 1);
//    wumpus = std::make_shared<wumpus_simulator::Wumpus>(tile);
//    tile->setMovable(std::dynamic_pointer_cast<wumpus_simulator::Movable>(wumpus));
//    model->setStench(0,1);

    //TRAPS
    tile = model->getTile(1, 0);
    tile->setTrap(true);
    model->setBreeze(1,0);

    tile = model->getTile(0, 0);
    tile->setTrap(true);
    model->setBreeze(0,0);

    tile = model->getTile(0, 2);
    tile->setTrap(true);
    model->setBreeze(0,2);

    generator::FileHandler fh(model);
    fh.extractFilename(false);
    fh.saveWWFile();
}