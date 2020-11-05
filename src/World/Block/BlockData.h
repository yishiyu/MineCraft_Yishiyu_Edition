//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCKDATA_H
#define MINECRAFT_YISHIYU_EDITION_BLOCKDATA_H

#include "Util/NonCopyable.h"
#include <SFML/Graphics.hpp>

// 方块渲染信息
struct BlockRenderData : public NonCopyable {
    sf::Vector2i texTopCoord;
    sf::Vector2i texSideCoord;
    sf::Vector2i texBottomCoord;
};

// 方块信息
// 1. 方块渲染信息
// 封装了自动从给定文件名获取方块信息的构造函数
class BlockData : public NonCopyable {
public:
    BlockData(const std::string &fileName);

    const BlockRenderData &getBlockRenderData() const;

private:
    BlockRenderData m_renderData;
};


#endif //MINECRAFT_YISHIYU_EDITION_BLOCKDATA_H
