//
// Created by Yishiyu on 2020/11/1.
//

#include "BasicTexture.h"

#include <SFML/Graphics.hpp>

BasicTexture::BasicTexture(const std::string &file) {
    loadFromFile(file);
}

void BasicTexture::loadFromImage(const sf::Image &image) {
    // 生成纹理并绑定
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    // 把加载的图片写到纹理缓冲区中
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

    // 设置两个方向的纹理环绕方式为"边缘拉伸"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

//    // 使用多级渐进纹理并设置缩小时使用两个最靠近的渐进纹理的线性插值
//    glGenerateMipmap(GL_TEXTURE_2D);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // 设置放大和缩小过滤方式为"线性过滤"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void BasicTexture::loadFromFile(const std::string &file) {
    // 用来读取图片的对象,在函数结束后回释放图片占用的内存
    sf::Image i;
    if (!i.loadFromFile("../Res/Textures/" + file + ".png")) {
        throw std::runtime_error(
                std::string(__FILE__) + std::string(__FUNCTION__) + "Unable to open image: " + file);
    }
    loadFromImage(i);
}

BasicTexture::~BasicTexture() {
    glDeleteTextures(1, &m_id);
}

void BasicTexture::bindTexture() const {
    glBindTexture(GL_TEXTURE_2D, m_id);
}

