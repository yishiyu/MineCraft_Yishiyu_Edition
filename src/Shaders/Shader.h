//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SHADER_H
#define MINECRAFT_YISHIYU_EDITION_SHADER_H

#include <string>
#include <glad/glad.h>

#include "../Maths/glm.h"

#include "../Util/NonCopyable.h"

// Shader基类,封装了加载shader,使用shader,向shader传送uniform数据
// 每个Shader都对应了一个GPU中的Shader,故不可复制
class Shader : NonCopyable {
public:
    Shader(const std::string &vertexFile, const std::string &fragmentFile);

    ~Shader();

    void useProgram() const;

    void loadInt(GLuint location, int value);

    void loadFloat(GLuint location, int value);

    void loadVector2(GLuint location, const glm::vec2 &vect);

    void loadVector3(GLuint location, const glm::vec3 &vect);

    void loadVector4(GLuint location, const glm::vec4 &vect);

    void loadMatrix4(GLuint location, const glm::mat4 &matrix);

protected:
    virtual void getUniforms() = 0;

    GLuint m_id;
};

#endif //MINECRAFT_YISHIYU_EDITION_SHADER_H
