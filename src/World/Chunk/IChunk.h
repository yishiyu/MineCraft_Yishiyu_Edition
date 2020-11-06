//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_ICHUNK_H
#define MINECRAFT_YISHIYU_EDITION_ICHUNK_H

#include "World/Block/Block.h"

// IChunk 接口
class IChunk{
public:
    virtual void setBlock(int x, int y, int z, Block block) = 0;
    virtual Block getBlock (int x, int y, int z) const = 0;
};

#endif //MINECRAFT_YISHIYU_EDITION_ICHUNK_H
