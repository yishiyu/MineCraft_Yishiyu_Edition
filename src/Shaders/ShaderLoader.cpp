//
// Created by Yishiyu on 2020/11/1.
//

#include "ShaderLoader.h"

#include "../Util/FileUtil.h"

#include <glad/glad.h>
#include <stdexcept>

namespace {
    GLuint compileShader(const GLchar *source, GLenum shaderType) {
        auto shaderID = glCreateShader(shaderType);

        glShaderSource(shaderID, 1, &source, nullptr);
        glCompileShader(shaderID);

        GLint isSuccess = 0;
        GLchar infoLog[512];

        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess);
        if (!isSuccess) {
            glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
            throw std::runtime_error("Unable to load a shader: " + std::string(infoLog));
        }

        return shaderID;
    }

    GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {
        auto id = glCreateProgram();

        glAttachShader(id, vertexShaderID);
        glAttachShader(id, fragmentShaderID);

        glLinkProgram(id);

        return id;
    }
}

GLuint loadShaders(const std::string &vertexShader,
                   const std::string &fragmentShader) {
    // 1. 从着色器文件中读取着色器源码(string)
    auto vertexSource = getFileContents("../Shaders/" + vertexShader + ".glsl");
    auto fragmentSource = getFileContents("../Shaders/" + fragmentShader + ".glsl");

    // 2. 创建两个着色器并编译
    auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
    auto fragmentShaderID = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

    // 3. 创建程序并链接两个着色器
    auto shaderID = linkProgram(vertexShaderID, fragmentShaderID);

    // 4. 删除已经不需要的着色器
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return shaderID;
}
