//
// Created by Yishiyu on 2020/11/6.
//

#include "SectionModelBuilder.h"

// 六个面的局部坐标
namespace {
    const std::vector<GLfloat> frontFace
            {
                    0, 0, 1,
                    1, 0, 1,
                    1, 1, 1,
                    0, 1, 1,
            };

    const std::vector<GLfloat> backFace
            {
                    1, 0, 0,
                    0, 0, 0,
                    0, 1, 0,
                    1, 1, 0,
            };

    const std::vector<GLfloat> leftFace
            {
                    0, 0, 0,
                    0, 0, 1,
                    0, 1, 1,
                    0, 1, 0,
            };

    const std::vector<GLfloat> rightFace
            {
                    1, 0, 1,
                    1, 0, 0,
                    1, 1, 0,
                    1, 1, 1,
            };

    const std::vector<GLfloat> topFace
            {
                    0, 1, 1,
                    1, 1, 1,
                    1, 1, 0,
                    0, 1, 0,
            };

    const std::vector<GLfloat> bottomFace
            {
                    0, 0, 0,
                    1, 0, 0,
                    1, 0, 1,
                    0, 0, 1
            };

}

// 快速计算一个方块调整后的位置
class AdjacentBlockPositions {
public:
    void update(int x, int y, int z) {
        up = {x, y + 1, z};
        down = {x, y - 1, z};
        left = {x - 1, y, z};
        right = {x + 1, y, z};
        front = {x, y, z + 1};
        back = {x, y, z - 1};
    }

    sf::Vector3i up;
    sf::Vector3i down;
    sf::Vector3i left;
    sf::Vector3i right;
    sf::Vector3i front;
    sf::Vector3i back;
};


SectionModelBuilder::SectionModelBuilder(Section &section)
        : m_pSection(&section) {

}

void SectionModelBuilder::buildModel(SectionModel &model) {
    m_pSectionModel = &model;

    AdjacentBlockPositions directions;

    // 对小区块中的所有方块操作
    for (int8_t y = 0; y < SECTION_SIZE; ++y){
        for (int8_t x = 0; x < SECTION_SIZE; ++x){
            for (int8_t z = 0; z < SECTION_SIZE; ++z) {
                sf::Vector3i position(x, y, z);
                Block block = m_pSection->getBlock(x, y, z);

                if (block == BlockDict::Air) {
                    continue;
                }

                m_pBlockRenderData = &(block.getBlockData().getBlockRenderData());
                auto &data = *m_pBlockRenderData;
                directions.update(x, y, z);

                // 上下面
                tryAddFaceToMesh(bottomFace, data.texBottomCoord, position, directions.down);
                tryAddFaceToMesh(topFace, data.texTopCoord, position, directions.up);

                // 左右
                tryAddFaceToMesh(leftFace, data.texSideCoord, position, directions.left);
                tryAddFaceToMesh(rightFace, data.texSideCoord, position, directions.right);

                // 前后
                tryAddFaceToMesh(frontFace, data.texSideCoord, position, directions.front);
                tryAddFaceToMesh(backFace, data.texSideCoord, position, directions.back);
            }
        }
    }


}

void SectionModelBuilder::tryAddFaceToMesh(const std::vector<GLfloat> &blockFace, const sf::Vector2i &textureCoords,
                                           const sf::Vector3i &blockPosition, const sf::Vector3i &blockFacing) {
    // 判断是否应该添加这个面然后添加之
    if (shouldMakeFace(blockFacing, *m_pBlockRenderData)) {
        // 根据纹理种类坐标获取纹理集中的纹理坐标
        auto texCoords = BlockDB::get().textureAtlas.getTexture(textureCoords);
        // 添加这个面
        m_pSectionModel->addFace(blockFace, texCoords, m_pSection->getLocation(), blockPosition);
    }
}

bool SectionModelBuilder::shouldMakeFace(const sf::Vector3i &blockPosition, const BlockRenderData &blockData) {
    // 获取这个位置的方块
    auto block = m_pSection->getBlock(blockPosition.x, blockPosition.y, blockPosition.z);
    // 如果这个方块是空气则这个面应该被渲染
    return (block == BlockDict::Air);
    ///@TODO Transparent Blocks
}
