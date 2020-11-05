//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BLOCKTYPE_H
#define MINECRAFT_YISHIYU_EDITION_BLOCKTYPE_H

#include "BlockData.h"
#include "Util/NonCopyable.h"
#include <string>

// 方块类型类
// 方块内中含有不可复制的 BlockData 对象,故不可复制
class BlockType : public NonCopyable {
public:
    BlockType(const std::string &filename);

    virtual ~BlockType() = default;

    const BlockData &getData() const;

private:
    BlockData m_blockData;

};

// 方块原型类
class BlockPrototype : public BlockType {
public:
    BlockPrototype(const std::string &filename) : BlockType(filename) {};
};

#endif //MINECRAFT_YISHIYU_EDITION_BLOCKTYPE_H
