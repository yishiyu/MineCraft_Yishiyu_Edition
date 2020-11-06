//
// Created by Yishiyu on 2020/11/1.
//

#include "RenderMaster.h"

void RenderMaster::drawQuad(const glm::vec3 &pos) {
    m_quadRenderer.add(pos);
}

void RenderMaster::drawCube(const glm::vec3 &pos) {
    m_cubeRenderer.add(pos);
}

void RenderMaster::drawSection(const SectionModel &model) {
    m_sectionRenderer.add(model);
}

void RenderMaster::finishRender(sf::RenderWindow &window, const Camera &camera) {
    // 清除缓存(包括颜色缓冲与深度缓冲)
    // 默认颜色为RGBA=(0.1,0.5,1.0,1.0)
    glClearColor(0.1, 0.5, 1.0, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    // 开启深度测试
    glEnable(GL_DEPTH_TEST);

    m_quadRenderer.renderQuads(camera);
    m_cubeRenderer.render(camera);
    m_sectionRenderer.render(camera);

    window.display();
}
