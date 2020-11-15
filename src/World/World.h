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

    void editBlock(int x, int y, int z, Block block);

    void renderWorld(RenderMaster &renderMaster);
    void addChunk(int x, int z);
private:
    std::vector<Chunk> m_chunks;
    std::vector<Chunk*> m_changedChunks;
};


#endif //MINECRAFT_YISHIYU_EDITION_WORLD_H