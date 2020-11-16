//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_MODEL_H
#define MINECRAFT_YISHIYU_EDITION_MODEL_H

#include <glad/glad.h>
#include <vector>

#include "Util/NonCopyable.h"
#include "Mesh.h"

// 存放一个BufferObject的位置,维度和索引
struct BufferObject {
    int index = 0;
    int dimensions = 0;
    GLuint buffer = 0;
};

// 模型类,模型内部绑定的VAO,VBO,EBO属于系统资源,故不可复制
// 保存了模型的顶点信息,贴图信息,下标信息
// 模型只能保存一份以上信息,重新添加的时候会删除之前添加的信息
// 1. 可以绑定数据的VAO
// 2. 可以添加VBO信息
// 但是不知道为什么没有绑定VBO和EBO的函数
class Model : public NonCopyable {
public:
    Model();

    Model(const Mesh &mesh);
    Model(Model &&model) noexcept;

    ~Model();

    void addData(const Mesh &mesh);
    void deleteData();

    void bindVAO() const;

    void bindData() const;
    void bindVBO() const;
    void bindEBO() const;

    int getIndicesCount() const;

private:
    void addVBO(int index,int dimensions, const std::vector<GLfloat>& data);
    void addEBO(const std::vector<GLuint> &indices);

    static GLuint m_VAO;
    std::vector<BufferObject> m_VBO;
    GLuint m_EBO = 0;
    int m_indicesCount = 0;

    bool m_isEmpty = true;
};


#endif //MINECRAFT_YISHIYU_EDITION_MODEL_H
