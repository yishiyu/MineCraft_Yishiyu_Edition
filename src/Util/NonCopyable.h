//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_NONCOPYABLE_H
#define MINECRAFT_YISHIYU_EDITION_NONCOPYABLE_H

class NonCopyable {
public:
    NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;

    NonCopyable &operator=(const NonCopyable &) = delete;
};


#endif //MINECRAFT_YISHIYU_EDITION_NONCOPYABLE_H
