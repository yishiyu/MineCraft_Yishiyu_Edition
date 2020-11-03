//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_CHUNKBLOCK_H
#define MINECRAFT_YISHIYU_EDITION_CHUNKBLOCK_H

#include "BlockId.h"

class ChunkBlock {
    ChunkBlock() = default;

    ChunkBlock(Block_t id);
    ChunkBlock(BlockId id);

    Block_t id = 0;
};


#endif //MINECRAFT_YISHIYU_EDITION_CHUNKBLOCK_H
