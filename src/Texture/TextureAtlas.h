//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_TEXTUREATLAS_H
#define MINECRAFT_YISHIYU_EDITION_TEXTUREATLAS_H

#include <vector>
#include "BasicTexture.h"

// 纹理图集
// 内含一个纹理图集总大小和一个单纹理大小
// 封装了根据纹理坐标获取纹理数据的方法(返回的是在纹理图集四个角坐标)
class TextureAtlas : public BasicTexture {
public:
    TextureAtlas(const std::string &textureFileName);

    std::vector<GLfloat> getTexture(const sf::Vector2i &coords);

private:
    int m_imageSize;
    int m_individualTextureSize;
};

#endif //MINECRAFT_YISHIYU_EDITION_TEXTUREATLAS_H
