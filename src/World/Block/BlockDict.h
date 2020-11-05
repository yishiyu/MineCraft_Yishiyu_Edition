//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCKDICT_H
#define MINECRAFT_YISHIYU_EDITION_BLOCKDICT_H

#include <cstdint>

// 方块类型id
using Block_t = uint8_t;

// 存储不同方块对应的id
enum class BlockDict : Block_t {
    Air = 0,
    Grass,
    Dirt,
    Stone,

    NUM_TYPES
};


#endif //MINECRAFT_YISHIYU_EDITION_BLOCKDICT_H
