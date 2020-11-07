//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SECTION_H
#define MINECRAFT_YISHIYU_EDITION_SECTION_H

#include "IChunk.h"
#include "World/WorldConstants.h"
#include "Model/SectionModel.h"

class Chunk;

class World;

// 小区块类
class Section : public IChunk {
    friend class Chunk;

public:
    Section(const sf::Vector3i &location, World &world);
    Section(Section&& section) noexcept;

    void setBlock(int x, int y, int z, Block block)override;

    Block getBlock(int x, int y, int z) const override;

    const sf::Vector3i getLocation() const noexcept;

private:
    sf::Vector3i toWorldPosition(int x, int y, int z) const;

    static bool outOfBounds(int value);

    static int getIndex(int x, int y, int z);

    std::array<Block, SECTION_VOLUME> m_blocks;
    SectionModel m_sectionModel;
    sf::Vector3i m_location;
    World *m_pWorld;
};


#endif //MINECRAFT_YISHIYU_EDITION_SECTION_H
