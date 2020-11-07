//
// Created by Yishiyu on 2020/11/3.
//

#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(const std::string &textureFileName) {
    sf::Image i;
    if (!i.loadFromFile("../../../Res/Textures/" + textureFileName + ".png")) {
        throw std::runtime_error(
                std::string(__FILE__) + std::string(__FUNCTION__) + "Unable to open image: " + textureFileName);
    }
    loadFromImage(i);

    // 设置总纹理大小(256x256)和单个纹理大小(16x16)
    m_imageSize = 256;
    m_individualTextureSize = 16;
}

std::vector<GLfloat> TextureAtlas::getTexture(const sf::Vector2i &coords) {
    // 计算每一行/列有多少个纹理
    static const GLfloat TEX_PER_ROW = (GLfloat) m_imageSize / (GLfloat) m_individualTextureSize;
    static const GLfloat INDV_TEX_SIZE = 1.0f / TEX_PER_ROW;
    static const GLfloat PIXEL_SIZE = 1.0f / (float) m_imageSize;

    // 获取目标纹理的左上角坐标
    GLfloat xMin = (coords.x * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE;
    GLfloat yMin = (coords.y * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE;
    // 获取目标纹理的右下角坐标
    GLfloat xMax = (xMin + INDV_TEX_SIZE) - 0.5 * PIXEL_SIZE;
    GLfloat yMax = (yMin + INDV_TEX_SIZE) - 0.5 * PIXEL_SIZE;

    // 返回目标纹理在图集中的坐标
    return
            {
                    xMax, yMax,
                    xMin, yMax,
                    xMin, yMin,
                    xMax, yMin
            };
}
