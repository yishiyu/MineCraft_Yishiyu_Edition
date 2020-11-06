//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SECTIONMODEL_H
#define MINECRAFT_YISHIYU_EDITION_SECTIONMODEL_H

#include "Model.h"
#include "SFML/Graphics.hpp"

// 小区块渲染模型类
class SectionModel : public Model {
public:
    SectionModel();

    // 为小区块模型添加一个面
    //
    void addFace(const std::vector<GLfloat> &blockFace,
                 const std::vector<GLfloat> &textureCoords,
                 const sf::Vector3i &sectionPosition,
                 const sf::Vector3i &blockPosition);

    // 加载小区块mesh为模型
    void bufferMesh();

private:
    // 小区块模型的mesh
    Mesh m_mesh;
    // 小区块模型中下标数组的下一个值
    GLuint m_indicesIndex = 0;

};


#endif //MINECRAFT_YISHIYU_EDITION_SECTIONMODEL_H
