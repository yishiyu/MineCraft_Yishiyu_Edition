//
// Created by Yishiyu on 2020/11/3.
//

#include "BlockData.h"

#include <fstream>

BlockData::BlockData(const std::string &fileName) {
    std::ifstream inFile("../Res/Blocks/" + fileName + ".block");

    if (!inFile.is_open()) {
        throw std::runtime_error("Unable to open block file: " + fileName + "!");
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (line == "TexTop") {
            int x, y;
            inFile >> x >> y;
            m_data.texTopCoord = {x, y};
        } else if (line == "TexSide") {
            int x, y;
            inFile >> x >> y;
            m_data.texSideCoord = {x, y};
        } else if (line == "TexBottom") {
            int x, y;
            inFile >> x >> y;
            m_data.texBottomCoord = {x, y};
        } else if (line == "TexAll") {
            int x, y;
            inFile >> x >> y;
            m_data.texTopCoord = {x, y};
            m_data.texSideCoord = {x, y};
            m_data.texBottomCoord = {x, y};
        }
    }
}

const BlockDataHolder &BlockData::getBlockData() const {
    return m_data;
}
