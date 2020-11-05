//
// Created by Yishiyu on 2020/11/5.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCKDB_H
#define MINECRAFT_YISHIYU_EDITION_BLOCKDB_H

#include "Util/Singleton.h"
#include "BlockType.h"
#include "BlockDict.h"
#include "Texture/TextureAtlas.h"
#include <array>
#include "BlockDict.h"

// 方块数据库类
// 使用单例模式
// 1. 所有方块实体的一个原型
// 2. 贴图集对象
// 可以根据方块类对应的id获取方块实体的原型
class BlockDB : public Singleton {
public:
    static BlockDB &get();

    const BlockPrototype &getBlockPrototype(Block_t id);

    const BlockData &getBlockData(Block_t id);

    TextureAtlas textureAtlas;

private:
    // 把构造函数设为私有,类外无法构造该类
    BlockDB();

    // 以固定长度存放所有方块的原型
    std::array<std::unique_ptr<BlockPrototype>, (unsigned) BlockDict::NUM_TYPES> m_blockPrototypes;
};


#endif //MINECRAFT_YISHIYU_EDITION_BLOCKDB_H
