//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BASICTEXTURE_H
#define MINECRAFT_YISHIYU_EDITION_BASICTEXTURE_H

#include <glad/glad.h>
#include <string>
#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.h"

// 基础纹理类
class BasicTexture {
public:
    BasicTexture() = default;

    BasicTexture(const std::string &file);

    ~BasicTexture();

    void loadFromImage(const sf::Image &image);

    void loadFromFile(const std::string &file);

    void bindTexture() const;

private:
    GLuint m_id;
};

#endif //MINECRAFT_YISHIYU_EDITION_BASICTEXTURE_H
