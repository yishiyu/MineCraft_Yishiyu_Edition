//
// Created by Yishiyu on 2020/11/6.
//

#include "World.h"
#include "WorldConstants.h"
#include <iostream>


World::World() {
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int z = 0; z < WORLD_SIZE; z++) {
            m_chunks.emplace_back(*this, sf::Vector2i(x, z));
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

}

Block World::getBlock(int x, int y, int z) const {
    int bX = x % SECTION_SIZE;
    int bZ = z % SECTION_SIZE;

    int cX = x / SECTION_SIZE;
    int cZ = z / SECTION_SIZE;

    if (cX < 0 || cX >= WORLD_SIZE ||
        cZ < 0 || cZ >= WORLD_SIZE) {
        return BlockDict::Air;
    }

    return m_chunks.at(cX*WORLD_SIZE+cZ).getBlock(bX,y,bZ);
}

void World::renderWorld(RenderMaster &renderMaster) {
    for(auto &chunk:m_chunks){
        chunk.drawChunk(renderMaster);
    }
}

