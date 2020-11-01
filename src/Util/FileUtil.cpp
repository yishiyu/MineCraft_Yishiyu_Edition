//
// Created by Yishiyu on 2020/11/1.
//

#include "FileUtil.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileUtil::getFileContents(const std::string &filePath) {
    std::ifstream inFile(filePath);
    if(!inFile.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::stringstream stream;

    stream << inFile.rdbuf();
    return stream.str();
}
