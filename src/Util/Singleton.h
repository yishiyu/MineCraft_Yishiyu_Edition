//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SINGLETON_H
#define MINECRAFT_YISHIYU_EDITION_SINGLETON_H

class Singleton {
public:
    Singleton(const Singleton &) = delete;

    Singleton(Singleton &&) = delete;

    Singleton &operator=(const Singleton &) = delete;

    Singleton &operator=(Singleton &&) = delete;

protected:
    Singleton() = default;
};


#endif //MINECRAFT_YISHIYU_EDITION_SINGLETON_H
