//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_MODEL_H
#define MINECRAFT_YISHIYU_EDITION_MODEL_H

#include <glad/glad.h>
#include <vector>

#include "Util/NonCopyable.h"

// 模型类,模型内部绑定的VAO,VBO,EBO属于系统资源,故不可复制
// 保存了模型的顶点信息,贴图信息,下标信息
// 模型只能保存一份以上信息,重新添加的时候会删除之前添加的信息
// 1. 可以绑定数据的VAO
// 2. 可以添加VBO信息
// 但是不知道为什么没有绑定VBO和EBO的函数
class Model : public NonCopyable {
public:
    Model() = default;

    Model(const std::vector<GLfloat> &vertexPositions,
          const std::vector<GLfloat> &textureCoords,
          const std::vector<GLuint> &indices);

    ~Model();

    void addData(const std::vector<GLfloat> &vertexPositions,
                 const std::vector<GLfloat> &textureCoords,
                 const std::vector<GLuint> &indices);

    void deleteData();

    void addVBO(int dimensions, const std::vector<GLfloat> &data);

    void bindVAO() const;

    //TODO: void bindVBO() const;
    //TODO: void bindEBO() const;

    int getIndicesCount() const;

private:
    void addEBO(const std::vector<GLuint> &indices);

    GLuint m_vao = 0;
    int m_vboCount = 0;
    int m_indicesCount = 0;
    std::vector<GLuint> m_buffers;
};


#endif //MINECRAFT_YISHIYU_EDITION_MODEL_H
