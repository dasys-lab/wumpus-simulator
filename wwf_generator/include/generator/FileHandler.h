#pragma once
#include <string>
#include <QtCore/QString>

namespace wumpus_simulator
{
class Model;
}

namespace generator
{
class FileHandler
{

public:
    FileHandler(wumpus_simulator::Model* model);

    // create filename with encoding of world
    std::string extractFilename(bool withAgents);
    void saveWWFile();

    std::string filename;


private:
    wumpus_simulator::Model* model;
};
}
