//
// Created by Administrator on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SHADERLOADER_H
#define MINECRAFT_YISHIYU_EDITION_SHADERLOADER_H

#include <string>
#include <glad/glad.h>

GLuint loadShaders(const std::string &vertexShader,
                   const std::string &fragmentShader);

#endif //MINECRAFT_YISHIYU_EDITION_SHADERLOADER_H
