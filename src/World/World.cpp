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

    int i=0;
    for (auto &chunk:m_chunks) {
        chunk.makeModels();
        if(++i==10) break;
        //TODO:在渲染到下标为240的区块时会触发vector越界异常,需要排除一下
    }
}

void World::setBlock(int x, int y, int z, Block block) {

}

Block World::getBlock(int x, int y, int z) const {
    int bX = x % SECTION_SIZE;
    int bZ = z % SECTION_SIZE;

    int cX = x / SECTION_SIZE;
    int cZ = z / SECTION_SIZE;

    if (cX < 0 || cX > WORLD_SIZE ||
        cZ < 0 || cZ > WORLD_SIZE) {
        return BlockDict::Air;
    }

    return m_chunks.at(cX*WORLD_SIZE+cZ).getBlock(bX,y,bZ);
}

void World::renderWorld(RenderMaster &renderMaster) {
    for(auto &chunk:m_chunks){
        chunk.drawChunk(renderMaster);
    }
}

