//
// Created by Yishiyu on 2020/11/3.
//

#include "Block.h"

Block::Block(Block_t id)
        : id(id) {

}

Block::Block(BlockDict id)
        : id(static_cast<Block_t>(id)) {
}

const BlockPrototype &Block::getBlockPrototype() {
    return BlockDB::get().getBlockPrototype(this->id);
}

const BlockData &Block::getBlockData() {
    return BlockDB::get().getBlockData(this->id);
}
