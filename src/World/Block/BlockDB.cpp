//
// Created by Administrator on 2020/11/5.
//

#include "BlockDB.h"

// 加载材质图集
BlockDB::BlockDB() : textureAtlas("DefaultPack.png") {
    // 依次加载所有方块(按道理来说应该是从配置文件中读取的)
    m_blockPrototypes[(int) BlockDict::Air] = std::make_unique<BlockPrototype>("Air");
    m_blockPrototypes[(int) BlockDict::Grass] = std::make_unique<BlockPrototype>("Grass");
    m_blockPrototypes[(int) BlockDict::Dirt] = std::make_unique<BlockPrototype>("Dirt");
    m_blockPrototypes[(int) BlockDict::Stone] = std::make_unique<BlockPrototype>("Stone");
}

BlockDB &BlockDB::get() {
    static BlockDB database;
    return database;
}

const BlockPrototype &BlockDB::getBlockPrototype(Block_t id) {
    return *(m_blockPrototypes[(int) id]);
}

const BlockData &BlockDB::getBlockData(Block_t id) {
    return m_blockPrototypes[(int) id]->getData();
}
