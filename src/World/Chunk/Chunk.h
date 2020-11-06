//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_CHUNK_H
#define MINECRAFT_YISHIYU_EDITION_CHUNK_H

#include "IChunk.h"
#include "Section.h"
#include "World/World.h"
#include "Renderer/RenderMaster.h"

class Chunk : public IChunk{
public:
    Chunk(World &world,const sf::Vector2i &location);

    // 构建所有Section的Model
    void makeModels();

    void setBlock (int x, int y, int z, Block block) override;
    Block getBlock (int x, int y, int z) const override;

    void drawChunk(RenderMaster& renderer);

private:
    bool outOfBound(int x,int y,int z) const;
    std::vector<Section> m_sections;
    sf::Vector2i  m_location;
    World* m_pWorld;
};


#endif //MINECRAFT_YISHIYU_EDITION_CHUNK_H
