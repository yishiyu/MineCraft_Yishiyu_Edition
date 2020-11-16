//
// Created by Yishiyu on 2020/11/1.
//

#include "Model.h"

GLuint Model::m_VAO = 0;

Model::Model():m_VBO() {
    // 如果公共的VAO没有初始化,则进行初始化
    if (m_VAO == 0) {
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);
    }
}

Model::Model(const Mesh &mesh):m_VBO() {
    // 如果公共的VAO没有初始化,则进行初始化
    if (m_VAO == 0) {
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);
    }
    addData(mesh);
}

Model::Model(Model &&model) noexcept {
    // 转移对象数据
    m_indicesCount = model.m_indicesCount;
    m_VBO.swap(model.m_VBO);
    m_EBO = model.m_EBO;
    m_isEmpty = false;
    // 使对象可以安全析构
    m_indicesCount = 0;
    model.m_EBO = 0;
    model.m_isEmpty = true;
}

Model::~Model() {
    deleteData();
}

void Model::bindVAO() const {
    glBindVertexArray(m_VAO);
}

// 保持原本的VAO不变,绑定VBO和EBO
void Model::bindData() const {
    bindVBO();
    bindEBO();
}

void Model::bindVBO() const {
    for (auto& buffer : m_VBO) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer.buffer);
        glVertexAttribPointer(buffer.index,
            buffer.dimensions,
            GL_FLOAT,
            GL_FALSE,
            0,
            (GLvoid*)0);

        glEnableVertexAttribArray(buffer.index);
    }

}

void Model::bindEBO() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void Model::addData(const Mesh &mesh) {
    if (!m_isEmpty) {
        deleteData();
    }

    addVBO(0, 3, mesh.vertexPosition);
    addVBO(1, 2, mesh.textureCoord);
    addEBO(mesh.indices);

    m_isEmpty = false;
}

void Model::addVBO(int index, int dimensions, const std::vector<GLfloat> &data) {
    GLuint vbo;
    glGenBuffers(1, &vbo);
    m_VBO.push_back({ index, dimensions, vbo });

    // 向VBO中写入数据
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
        data.size() * sizeof(GLfloat),
        data.data(),
        GL_STATIC_DRAW);
}

void Model::addEBO(const std::vector<GLuint> &indices) {
    GLuint ebo;
    glGenBuffers(1, &ebo);
    m_EBO = ebo;

    // 向EBO中写入数据
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof(GLuint),
                 indices.data(),
                 GL_STATIC_DRAW);
    m_indicesCount = indices.size();
}

void Model::deleteData() {

    for (auto& buffer : m_VBO) {
        glDeleteBuffers(1, &(buffer.buffer));
    }
    glDeleteBuffers(1, &m_EBO);

    m_VBO.clear();
    m_EBO = 0;

    m_indicesCount = 0;

    m_isEmpty = true;
}

int Model::getIndicesCount() const {
    return m_indicesCount;
}
