//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SECTIONMODELBUILDER_H
#define MINECRAFT_YISHIYU_EDITION_SECTIONMODELBUILDER_H

#include "Section.h"

class SectionModelBuilder {
public:
    SectionModelBuilder(Section &section, SectionModel& model);

    void buildModel();

private:
    void tryAddFaceToMesh(const std::vector<GLfloat> &blockFace,
                          const sf::Vector2i &textureCoords,
                          const sf::Vector3i &blockPosition,
                          const sf::Vector3i &blockFacing);

    bool shouldMakeFace(const sf::Vector3i &blockPosition,
                        const BlockRenderData &blockData);

    Section *m_pSection = nullptr;
    SectionModel *m_pSectionModel = nullptr;
    // 这个const修饰的是指向的对象,而不是指针本身
    const BlockRenderData*  m_pBlockRenderData    = nullptr;
};


#endif //MINECRAFT_YISHIYU_EDITION_SECTIONMODELBUILDER_H
