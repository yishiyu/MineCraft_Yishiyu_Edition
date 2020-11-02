//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SHADERLOADER_H
#define MINECRAFT_YISHIYU_EDITION_SHADERLOADER_H

#include <string>
#include <glad/glad.h>

// 从着色器文件读取源码,编译,链接,返回一个着色器程序ID
GLuint loadShaders(const std::string &vertexShader,
                   const std::string &fragmentShader);

#endif //MINECRAFT_YISHIYU_EDITION_SHADERLOADER_H
