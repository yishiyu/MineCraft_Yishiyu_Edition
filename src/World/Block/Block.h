//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCK_H
#define MINECRAFT_YISHIYU_EDITION_BLOCK_H

#include "BlockDict.h"
#include "BlockDB.h"

class BlockData;

class BlockPrototype;

// 方块实体类
// 1. 方块类型对应的id
// 通过 BlockDB 可以获取该方块类型的具体信息
class Block {
public:
    Block() = default;

    Block(Block_t id);

    Block(BlockDict id);

    const BlockPrototype &getBlockPrototype();

    const BlockData &getBlockData();

    bool operator==(const Block &another) {
        return another.id == this->id;
    }

    bool operator!=(const Block& another) {
        return another.id != this->id;
    }

    Block_t id = 0;
};


#endif //MINECRAFT_YISHIYU_EDITION_BLOCK_H
