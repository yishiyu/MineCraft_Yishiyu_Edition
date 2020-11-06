//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SECTIONRENDERER_H
#define MINECRAFT_YISHIYU_EDITION_SECTIONRENDERER_H

#include "Shaders/SectionShader.h"
#include <vector>

class Camera;
class SectionModel;

// 小区块渲染类
class SectionRenderer {
public:
    void add(const SectionModel& model);
    void render(const Camera& camera);

private:
    std::vector<const SectionModel*> m_sectionModels;
    SectionShader m_sectionShader;

};


#endif //MINECRAFT_YISHIYU_EDITION_SECTIONRENDERER_H
