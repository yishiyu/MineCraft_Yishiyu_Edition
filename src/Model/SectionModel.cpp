//
// Created by Yishiyu on 2020/11/6.
//

#include "SectionModel.h"
#include "World/WorldConstants.h"


SectionModel::SectionModel() {

}

void SectionModel::addFace(const std::vector<GLfloat> &blockFace, const std::vector<GLfloat> &textureCoords,
                           const sf::Vector3i &sectionPosition, const sf::Vector3i &blockPosition) {

    auto &m_vertexes = m_mesh.vertexPosition;
    auto &m_textureCoords = m_mesh.textureCoord;
    auto &m_indices = m_mesh.indices;

    // 添加纹理下标序列
    m_textureCoords.insert(m_textureCoords.end(), textureCoords.begin(), textureCoords.begin());

    // 添加顶点序列(世界坐标)(三维 * 四个点 = 12个数据)
    // i : 四个点
    // index : 12个数据在输入vector中的下标
    for (int i = 0, index = 0; i < 4; i++) {
        // 在这一步直接转换成世界坐标,所以在 Shader 中不用再乘以 Model Matrix
        // 世界坐标 = 所在小区块坐标 * 小区块边长 + 方块在小区块中的坐标 + 顶点的局部坐标
        m_vertexes.push_back(sectionPosition.x * SECTION_SIZE + blockPosition.x + blockFace[index++]);
        m_vertexes.push_back(sectionPosition.y * SECTION_SIZE + blockPosition.y + blockFace[index++]);
        m_vertexes.push_back(sectionPosition.z * SECTION_SIZE + blockPosition.z + blockFace[index++]);
    }

    // 添加下标序列(即要被渲染的三角形的顶点序列)
    // 函数原型为: iterator insert( const_iterator pos, std::initializer_list<T> ilist );
    m_indices.insert(m_indices.end(),
                     {m_indicesIndex,
                      m_indicesIndex + 1,
                      m_indicesIndex + 2,

                      m_indicesIndex + 2,
                      m_indicesIndex + 3,
                      m_indicesIndex});

    // 更新下标序列(新加入了4个顶点)
    m_indicesIndex += 4;

}

void SectionModel::bufferMesh() {
    // 加载mesh到model中(会清空上一个model)
    addData(m_mesh);

    // 清空mesh中的数据
    m_mesh.vertexPosition.clear();
    m_mesh.indices.clear();
    m_mesh.textureCoord.clear();

    // 释放mesh数据结构中的空间
    m_mesh.textureCoord.shrink_to_fit();
    m_mesh.indices.shrink_to_fit();
    m_mesh.vertexPosition.shrink_to_fit();

    // 复原下标
    m_indicesIndex = 0;
}
