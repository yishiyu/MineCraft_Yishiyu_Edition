//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_STATEBASE_H
#define MINECRAFT_YISHIYU_EDITION_STATEBASE_H

#include <SFML/Graphics.hpp>

class RenderMaster;

class Application;

// State基类(虚类)
// 一个State必须重载
// 1. 处理SFML事件
// 2. 处理输入
// 3. 根据时间间隔更新状态
// 4. 渲染画面
// 同时一个State必须持有一个应用实例
class StateBase {
public:
    StateBase(Application &app)
            : m_pApplication(&app) {}

    virtual ~StateBase() noexcept = default;

    virtual void handleEvent(sf::Event e) = 0;

    virtual void handleInput() = 0;

    virtual void update(float deltaTime) = 0;

    virtual void render(RenderMaster &renderer) = 0;

protected:
    Application *m_pApplication;

};


#endif //MINECRAFT_YISHIYU_EDITION_STATEBASE_H
