//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_RENDERMASTER_H
#define MINECRAFT_YISHIYU_EDITION_RENDERMASTER_H

#include <SFML/Graphics.hpp>
#include "QuadRenderer.h"
#include "CubeRenderer.h"
#include "SectionRenderer.h"

class Camera;

// 渲染管理器
// 持有一个四边形渲染器
// 可以添加四边形位置和完成一次完整渲染
class RenderMaster {
public:
    void drawQuad(const glm::vec3 &pos);
    void drawCube(const glm::vec3 &pos);
    void drawSection(const SectionModel &model);

    // 完成一次完整渲染,包括清空上一次的缓冲(包括颜色缓冲和深度缓冲),渲染和显示
    void finishRender(sf::RenderWindow &window, const Camera &camera);

private:
    QuadRenderer m_quadRenderer;
    CubeRenderer m_cubeRenderer;
    SectionRenderer m_sectionRenderer;
};


#endif //MINECRAFT_YISHIYU_EDITION_RENDERMASTER_H
