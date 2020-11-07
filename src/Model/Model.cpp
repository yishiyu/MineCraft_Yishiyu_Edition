//
// Created by Yishiyu on 2020/11/1.
//

#include "Model.h"

Model::Model(const Mesh &mesh) {
    addData(mesh);
}

Model::Model(Model &&model) noexcept {
    // 转移对象数据
    m_vao = model.m_vao;
    m_vboCount = model.m_vboCount;
    m_indicesCount = model.m_indicesCount;
    m_buffers.swap(model.m_buffers);
    // 使对象可以安全析构
    m_vao = 0;
    m_vboCount=0;
    m_indicesCount = 0;
}

Model::~Model() {
    deleteData();
}

void Model::bindVAO() const {
    glBindVertexArray(m_vao);
}

void Model::addData(const Mesh &mesh) {
    if (m_vao != 0)
        deleteData();

    m_indicesCount = mesh.indices.size();

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    addVBO(3, mesh.vertexPosition);
    addVBO(2, mesh.textureCoord);
    addEBO(mesh.indices);
}

void Model::addVBO(int dimensions, const std::vector<GLfloat> &data) {
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 data.size() * sizeof(GLfloat),
                 data.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(m_vboCount,
                          dimensions,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (GLvoid *) 0);

    glEnableVertexAttribArray(m_vboCount++);

    m_buffers.push_back(vbo);
}

// 很奇怪,为什么把EBO保存到缓存vector中?
// 删除缓存的时候应该是也要删除EBO的,可能是大佬忘记写了吧
void Model::addEBO(const std::vector<GLuint> &indices) {
    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof(GLuint),
                 indices.data(),
                 GL_STATIC_DRAW);
    //TODO: Add the EBO to m_buffers
}

void Model::deleteData() {
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(m_buffers.size(),
                    m_buffers.data());

    m_buffers.clear();

    m_vboCount = 0;
    m_vao = 0;
    m_indicesCount = 0;
}

int Model::getIndicesCount() const {
    return m_indicesCount;
}
