//
// Created by Yishiyu on 2020/11/6.
//

#include "Chunk.h"
#include "SectionModelBuilder.h"
#include <iostream>

Chunk::Chunk(World &world, const sf::Vector2i &location)
        : m_location(location), m_pWorld(&world) {
    // 每个大区块3个小区块
    for (int y = 0; y < 3; y++) {
        m_sections.emplace_back(sf::Vector3i(location.x, y, location.y), world);
    }
}

void Chunk::makeModels() {
    static int i=0;
    for (auto &section : m_sections) {
        ++i;
        auto builder = SectionModelBuilder(section);
        builder.buildModel(section.m_sectionModel);
        section.m_sectionModel.bufferMesh();
    }
}

void Chunk::setBlock(int x, int y, int z, Block block) {
    if (outOfBound(x, y, z)) {
        //TODO:超出范围后委托给World
        return;
    }

    int bY = y % SECTION_SIZE;

    m_sections.at(y / SECTION_SIZE).setBlock(x, bY, z,block);
}

Block Chunk::getBlock(int x, int y, int z) const {
    if (outOfBound(x, y, z)) {
        return BlockDict::Air;
    }

    int bY = y % SECTION_SIZE;

    return m_sections.at(y / SECTION_SIZE).getBlock(x, bY, z);
}

void Chunk::drawChunk(RenderMaster &renderer) {
    for(auto &section : m_sections){
        renderer.drawSection(section.m_sectionModel);
    }
}

bool Chunk::outOfBound(int x, int y, int z) const {
    if (x >= SECTION_SIZE) return true;
    if (z >= SECTION_SIZE) return true;
    if (y >= (int)m_sections.size() * SECTION_SIZE){
        return true;
    }

    if (x < 0) return true;
    if (y < 0) return true;
    if (z < 0) return true;

    return false;
}
