//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_CONTEXT_H
#define MINECRAFT_YISHIYU_EDITION_CONTEXT_H

#include <SFML/Graphics.hpp>

// 应用的上下文类
// 持有一个窗口对象
// 在创建的同时会完成窗口上下文的设置和glad的初始化
class Context {
public:
    Context();

    sf::RenderWindow window;
};


#endif //MINECRAFT_YISHIYU_EDITION_CONTEXT_H
