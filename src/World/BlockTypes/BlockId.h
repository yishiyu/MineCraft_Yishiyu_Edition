//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCKID_H
#define MINECRAFT_YISHIYU_EDITION_BLOCKID_H

#include <cstdint>

using Block_t = uint8_t;

enum class BlockId : Block_t {
    Air = 0,
    Grass,
    Dirt,
    Stone,

    NUM_TYPES
};


#endif //MINECRAFT_YISHIYU_EDITION_BLOCKID_H
