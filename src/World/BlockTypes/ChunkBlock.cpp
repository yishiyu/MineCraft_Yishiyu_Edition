//
// Created by Yishiyu on 2020/11/3.
//

#include "ChunkBlock.h"

ChunkBlock::ChunkBlock(Block_t id)
        : id(id) {

}

ChunkBlock::ChunkBlock(BlockId id)
        : id(static_cast<Block_t>(id)) {

}
