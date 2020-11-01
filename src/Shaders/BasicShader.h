//
// Created by Administrator on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BASICSHADER_H
#define MINECRAFT_YISHIYU_EDITION_BASICSHADER_H

#include "Shader.h"

class BasicShader : public Shader {
public:
    BasicShader(const std::string &vertexFile = "BasicVertex",
                const std::string &fragmentFile = "BasicFragment");

    void loadProjectionViewMatrix(const glm::mat4 &pvMatrix);

private:
    virtual void getUniforms() override;

    GLuint m_locationProjectionViewMatrix;
};


#endif //MINECRAFT_YISHIYU_EDITION_BASICSHADER_H
