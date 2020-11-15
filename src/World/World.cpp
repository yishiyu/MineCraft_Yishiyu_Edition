//
// Created by Yishiyu on 2020/11/6.
//

#include "World.h"
#include "WorldConstants.h"
#include <iostream>

namespace {
    struct VectorXZ {
        int x, z;
    };

    // Block的世界坐标 ==> Block在Section中的坐标
    VectorXZ getBlockXZ(int x, int z) {
        return{
            x % SECTION_SIZE,
            z % SECTION_SIZE
        };
    }
    // Block的世界坐标 ==> Chunk/Section的世界坐标
    VectorXZ getChunkXZ(int x, int z) {
        return{
            x / SECTION_SIZE,
            z / SECTION_SIZE
        };
    }
    // Block是否超出世界坐标
    bool isOutOfBounds(const VectorXZ& chunkPos) {
        if (chunkPos.x < 0) return true;
        if (chunkPos.z < 0) return true;
        if (chunkPos.x >= WORLD_SIZE) return true;
        if (chunkPos.z >= WORLD_SIZE) return true;
        return false;
    }
}

World::World() {
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int z = 0; z < WORLD_SIZE; z++) {
            addChunk(x, z);
        }
    }

    for (auto &chunk:m_chunks) {
        chunk.makeModels();
        // 找到错误原因了:Chunk 会调用 World::getBlock 来获取自身以外方块的信息
        // 之前的 World::getBlock 中判定越界的表达式错了,导致会查看不存在区块的方块而不是直接返回 BlockDict::Air
        // 把原本的    if (cX < 0 || cX > WORLD_SIZE ||
        //               cZ < 0 || cZ > WORLD_SIZE) {
        //               return BlockDict::Air;
        //            }
        // 改为       if (cX < 0 || cX >= WORLD_SIZE ||
        //               cZ < 0 || cZ >= WORLD_SIZE) {
        //               return BlockDict::Air;
        //            }
        // 轻松解决问题...
    }
}

void World::setBlock(int x, int y, int z, Block block) {
    auto bp = getBlockXZ(x, z);
    auto cp = getChunkXZ(x, z);

    if (isOutOfBounds(cp)) {
        return;
    }

    m_chunks.at(cp.x * WORLD_SIZE + cp.z).setBlock(bp.x, y, bp.z, block);
}

Block World::getBlock(int x, int y, int z) const {
    auto bp = getBlockXZ(x, z);
    auto cp = getChunkXZ(x, z);

    if (isOutOfBounds(cp)) {
        return BlockDict::Air;
    }

    return m_chunks.at(cp.x * WORLD_SIZE + cp.z).getBlock(bp.x, y, bp.z);
}

void World::editBlock(int x, int y, int z, Block block) {
    auto cp = getChunkXZ(x, z);

    if (isOutOfBounds(cp)) {
        return;
    }

    setBlock(x, y, z, block);
    m_changedChunks.push_back(&m_chunks.at(cp.x * WORLD_SIZE + cp.z));
}

void World::renderWorld(RenderMaster &renderMaster) {
    // 重新渲染被改动的区块
    for (auto& chunk : m_changedChunks) {
        chunk->makeModels();
    }
    m_changedChunks.clear();

    for(auto &chunk:m_chunks){
        chunk.drawChunk(renderMaster);
    }
}

void World::addChunk(int x, int z) {
    m_chunks.emplace_back(*this, sf::Vector2i(x, z));
}

