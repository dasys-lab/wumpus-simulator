#include "generator/FileHandler.h"
#include <SystemConfig.h>
#include <iostream>
#include <model/Model.h>
#include <ros/ros.h>
#include <regex>

int getBoundedRand(int minValue, int maxValue)
{
    if((maxValue - minValue) == 0) {
        return maxValue;
    }
    return ((rand() % (maxValue - minValue)) + minValue);
}

int main(int argc, char* argv[])
{

    std::string inquiry = "holds(on(wildcard,wildcard),wildcard)";


    auto sc = essentials::SystemConfig::getInstance();

    auto numWorlds = (*sc)["WWFGenerator"]->get<int>("Generator.nWorlds", NULL);
    auto playgroundMin = (*sc)["WWFGenerator"]->get<int>("Generator.playgroundMin", NULL);
    auto playgroundMax = (*sc)["WWFGenerator"]->get<int>("Generator.playgroundMax", NULL);

    auto trapMin = (*sc)["WWFGenerator"]->get<int>("Generator.trapMin", NULL);
    auto trapMax = (*sc)["WWFGenerator"]->get<int>("Generator.trapMax", NULL);
    auto wumpusMin = (*sc)["WWFGenerator"]->get<int>("Generator.wumpusMin", NULL);
    auto wumpusMax = (*sc)["WWFGenerator"]->get<int>("Generator.wumpusMax", NULL);

    auto arrowConfig = (*sc)["WWFGenerator"]->get<int>("Generator.arrow", NULL);

    // needed for node in wumpus simulator model
    ros::init(argc, argv, essentials::SystemConfig::getInstance()->getHostname() + "_wwfgen");

    std::vector<std::string> modelNames;

    int playgroundSize;
    int wumpusCount;
    int trapCount;

    std::string nWorlds = std::to_string(numWorlds);
    std::string playgroundString;
    std::string wumpusString;
    std::string trapString;
    std::string arrow = std::to_string(arrowConfig);

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-n" || std::string(argv[i]) == "--worlds") {
            nWorlds = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-s" || std::string(argv[i]) == "--size") {
            playgroundString = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-w" || std::string(argv[i]) == "--wumpi") {
            wumpusString = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-t" || std::string(argv[i]) == "--traps") {
            trapString = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-a" || std::string(argv[i]) == "--arrow") {
            arrow = argv[i + 1];
            i++;
        }
    }

    std::cout << "generating " << std::stoi(nWorlds) << "Worlds in total!" << std::endl;

    /* initialize random seed: */
    srand(time(NULL));

    // generate n models
    for (int i = 0; i < std::stoi(nWorlds); ++i) {

        playgroundSize = (playgroundString.empty() ? getBoundedRand(playgroundMin, playgroundMax) : std::stoi(playgroundString));
        wumpusCount = (wumpusString.empty() ? getBoundedRand(wumpusMin, wumpusMax) : std::stoi(wumpusString));
        trapCount = (trapString.empty() ? getBoundedRand(trapMin, trapMax) : std::stoi(trapString));

        std::cout << "generating "
                  << "model with playground size " << std::to_string(playgroundSize) << ", wumpus count is " << std::to_string(wumpusCount) << ", trapCount is "
                  << std::to_string(trapCount) << std::endl;
        wumpus_simulator::Model* model = wumpus_simulator::Model::get();

        model->init(std::stoi(arrow), wumpusCount, trapCount, playgroundSize);
        generator::FileHandler fh(model);
        fh.extractFilename(false);
        if (std::find(modelNames.begin(), modelNames.end(), fh.filename) == modelNames.end()) {
            fh.saveWWFile();
            std::cout << "New world!" << fh.filename << std::endl;
            modelNames.push_back(fh.filename);
        } else {
            std::cout << "world config " << fh.filename << "already exists. creating new world." << std::endl;
            i -= 1;
        }

        // sleep to avoid many worlds with the same configuration being generated (probably happened because random seed of wsim depends on time)
        sleep(1);
    }

}
