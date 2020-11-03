//
// Created by Yishiyu on 2020/11/1.
//

#include "Context.h"

#include <glad/glad.h>

Context::Context() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    window.create({1280, 720}, "Minecraft", sf::Style::Close, settings);

    // 使用glad初始化OpenGL
    gladLoadGL();
    // 剔除方块的反面
    glCullFace(GL_BACK);

    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
}
