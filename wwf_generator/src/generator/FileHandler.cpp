#include "generator/FileHandler.h"
#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <iostream>
#include <model/Agent.h>
#include <model/Model.h>
#include <sstream>
#include <utility>

namespace generator
{

FileHandler::FileHandler(wumpus_simulator::Model* model)
        : model(model)
        , filename("")
{
}

std::string FileHandler::extractFilename(bool withAgents)
{

    //    auto t = std::time(nullptr);
    //    auto tm = *std::localtime(&t);
    //    std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;

    auto wumpusPositions = std::vector<std::pair<int, int>>();
    auto trapPositions = std::vector<std::pair<int, int>>();
    auto agentPositions = std::vector<std::pair<int, int>>();

    std::pair<int, int> goldPosition = {-1, -1};

    for (int i = 0; i < model->getPlayGroundSize(); ++i) {
        for (int j = 0; j < model->getPlayGroundSize(); ++j) {
            auto tile = model->getTile(i, j);
            if (tile->getMovable()) {
                if (tile->getMovable()->getType().compare(QString::fromStdString("wumpus")) == 0) {
                    wumpusPositions.push_back(std::make_pair(i, j));
                }
                if (tile->getMovable()->getType().compare(QString::fromStdString("agent")) == 0) {
                    agentPositions.push_back(std::make_pair(i, j));
                }
            }
            if (tile->getTrap()) {
                trapPositions.push_back(std::make_pair(i, j));
            }
            if (tile->getGold()) {
                goldPosition = {i, j};
            }
        }
    }

    std::stringstream ss;

    ss << "pg";
    ss << model->getPlayGroundSize();
    if (model->getWumpusCount() > 0) {
        ss << "w";
        for (int i = 0; i < wumpusPositions.size(); ++i) {
            auto wPos = wumpusPositions.at(i);
            ss << wPos.first << "-" << wPos.second;
            if (i != wumpusPositions.size() - 1) {
                ss << "_";
            }
        }
    }

    if (model->getTrapCount() > 0) {

        ss << "t";
        for (int i = 0; i < trapPositions.size(); ++i) {
            auto tPos = trapPositions.at(i);
            ss << tPos.first << "-" << tPos.second;
            if (i != trapPositions.size() - 1) {
                ss << "_";
            }
        }
    }

    ss << "g" << goldPosition.first << "-" << goldPosition.second;

    if (withAgents) {
        ss << "a";
        for (int i = 0; i < agentPositions.size(); ++i) {
            auto aPos = agentPositions.at(i);
            auto agent = std::dynamic_pointer_cast<wumpus_simulator::Agent>(model->getTile(aPos.first, aPos.second)->getMovable());
            ss << aPos.first << "-" << aPos.second << "-" << agent->hasArrow() << "-" << agent->getHasGold();

            if (i != agentPositions.size() - 1) {
                ss << "_";
            }
        }
    }

    this->filename = ss.str();
    return ss.str();
}

void FileHandler::saveWWFile()
{

    if (this->filename.empty()) {
        std::cerr << "Filename not set, please call extract filename first" << std::endl;
    }
    QString qFilename = QString::fromStdString(this->filename);

    if (!qFilename.endsWith(".wwf")) {
        qFilename += ".wwf";
    }

    // Create file
    QFile file(qFilename);

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    // Serialize the world as JSON
    if (this->model != nullptr) {
        auto worldJson = this->model->toJSON();

        // Write to file
        QJsonDocument saveDoc(worldJson);
        file.write(saveDoc.toJson());
    }
    file.close();
}
}
