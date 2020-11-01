//
// Created by Administrator on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_RENDERMASTER_H
#define MINECRAFT_YISHIYU_EDITION_RENDERMASTER_H

#include "QuadRenderer.h"
#include <SFML/Graphics.hpp>

class Camera;

class RenderMaster {
public:
    void drawQuad(const glm::vec3 &pos);

    void finishRender(sf::RenderWindow &window, const Camera &camera);

private:
    QuadRenderer m_quadRenderer;
};


#endif //MINECRAFT_YISHIYU_EDITION_RENDERMASTER_H
