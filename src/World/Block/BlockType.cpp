//
// Created by Yishiyu on 2020/11/5.
//

#include "BlockType.h"

const BlockData &BlockType::getData() const {
    return m_blockData;
}

BlockType::BlockType(const std::string &filename) : m_blockData(filename) {

}
