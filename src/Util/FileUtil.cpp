//
// Created by Yishiyu on 2020/11/1.
//

#include "FileUtil.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string getFileContents(const std::string &filePath) {
    // 根据文件名建立文件流
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        throw std::runtime_error(std::string(__FILE__) + std::string(__FUNCTION__) + "Unable to open file: " + filePath);
    }

    std::stringstream stream;

    // 从文件输入流中读取数据到字符串流中
    stream << inFile.rdbuf();
    return stream.str();
}
