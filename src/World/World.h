//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_WORLD_H
#define MINECRAFT_YISHIYU_EDITION_WORLD_H

#include "Chunk/IChunk.h"
#include "Chunk/Chunk.h"
#include "Renderer/RenderMaster.h"

class World : public IChunk {
public:
    World();

    void setBlock(int x, int y, int z, Block block) override;

    Block getBlock(int x, int y, int z) const override;

    void renderWorld(RenderMaster &renderMaster);

private:
    std::vector<Chunk> m_chunks;
};


#endif //MINECRAFT_YISHIYU_EDITION_WORLD_H
//#include <vector>
//#include "Chunk/Chunk.h"
//
//class RenderMaster;
//
//class World : IChunk
//{
//public:
//    World();
//
//    ChunkBlock  getBlock    (int x, int y, int z) const             override;
//    void        setBlock    (int x, int y, int z, ChunkBlock block) override;
//
//    void renderWorld(RenderMaster& master);
//
//private:
//    std::vector<Chunk> m_chunks;
//};