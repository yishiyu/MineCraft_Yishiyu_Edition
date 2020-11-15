//
// Created by Yishiyu on 2020/11/6.
//

#include "Section.h"
#include "Chunk.h"
#include "World/World.h"

Section::Section(const sf::Vector3i &location, World &world)
        : m_location(location), m_pWorld(&world) {
    for(auto &block : m_blocks){
        block = Block(BlockDict::Stone);
    }
}

Section::Section(Section &&section) noexcept
    :m_sectionModel(std::move(section.m_sectionModel)){
    // 显式调用SectionModel的移动构造函数
    // 指针直接复制
    m_pWorld = section.m_pWorld;
    // array交换两个section对象的内容
    m_blocks.swap(section.m_blocks);
    // 三维向量直接复制
    m_location = section.m_location;
    // model对象现在已经可以析构了
}

void Section::setBlock(int x, int y, int z, Block block) {
    // 如果超出范围则委托给World
    if (outOfBounds(x) ||
        outOfBounds(y) ||
        outOfBounds(z)) {
        auto location = toWorldPosition(x, y, z);
        m_pWorld->setBlock(location.x, location.y, location.z, block);
        return;
    }
    // 设置自身方块
    m_blocks[getIndex(x, y, z)] = block;
    m_hasMesh = false;
}

Block Section::getBlock(int x, int y, int z) const {
    // 如果超出范围则委托给World
    if (outOfBounds(x) ||
        outOfBounds(y) ||
        outOfBounds(z)) {
        auto location = toWorldPosition(x, y, z);
        return m_pWorld->getBlock(location.x, location.y, location.z);
    }
    // 返回自身方块
    return m_blocks[getIndex(x, y, z)];
}

const sf::Vector3i Section::getLocation() const noexcept {
    return m_location;
}

bool Section::hasMesh() const noexcept{
    return m_hasMesh;
}

sf::Vector3i Section::toWorldPosition(int x, int y, int z) const {
    // 把当前小区块的相对坐标转换为世界坐标
    return {
            m_location.x * SECTION_SIZE + x,
            m_location.y * SECTION_SIZE + y,
            m_location.z * SECTION_SIZE + z
    };
}

bool Section::outOfBounds(int value) {
    // 判定是否在合法范围内
    return value >= SECTION_SIZE ||
           value < 0;
}

int Section::getIndex(int x, int y, int z) {
    return y * SECTION_AREA +
           z * SECTION_SIZE +
           x;
}

