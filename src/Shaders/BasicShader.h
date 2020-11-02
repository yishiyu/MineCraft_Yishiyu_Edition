//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BASICSHADER_H
#define MINECRAFT_YISHIYU_EDITION_BASICSHADER_H

#include "Shader.h"

// 使用"基础顶点着色器"和"基础片段着色器"的着色器类
// 封装了找到两个着色器中uniform变量和向其传送数据的方法(模型矩阵,投影视图矩阵)
class BasicShader : public Shader {
public:
    BasicShader(const std::string &vertexFile = "BasicVertex",
                const std::string &fragmentFile = "BasicFragment");

    void loadProjectionViewMatrix   (const glm::mat4& pvMatrix);
    void loadModelMatrix            (const glm::mat4& matrix);

private:
    virtual void getUniforms() override;

    GLuint m_locationProjectionViewMatrix;
    GLuint m_locationModelMatrix;
};


#endif //MINECRAFT_YISHIYU_EDITION_BASICSHADER_H
