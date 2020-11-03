//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCKDATA_H
#define MINECRAFT_YISHIYU_EDITION_BLOCKDATA_H

#include "Util/NonCopyable.h"
#include <SFML/Graphics.hpp>

struct BlockDataHolder : public NonCopyable {
    sf::Vector2i texTopCoord;
    sf::Vector2i texSideCoord;
    sf::Vector2i texBottomCoord;
};

class BlockData : public NonCopyable {
public:
    BlockData(const std::string &fileName);

    const BlockDataHolder &getBlockData() const;

private:
    BlockDataHolder m_data;
};


#endif //MINECRAFT_YISHIYU_EDITION_BLOCKDATA_H
