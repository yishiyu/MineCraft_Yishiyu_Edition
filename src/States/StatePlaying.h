//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H
#define MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H

#include "StateBase.h"
#include "Player/Player.h"
#include "World/World.h"

enum Events {
    NONE_EVENT,
    MOUSE_LEFT_DOWN,
    MOUSE_RIGHT_DOWN,
};

// 游戏状态,继承自状态基类
// 持有一个Player对象
// 在初始化的时候设置Application对象的Camera对象跟随Player对象(Entity子类)
class StatePlaying : public StateBase {
public:
    StatePlaying(Application &app);

    void handleEvent(sf::Event e) override;

    void handleInput() override;

    void update(float deltaTime) override;

    void render(RenderMaster &renderer) override;

private:
    Player m_player;
    World m_world;
};

#endif //MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H
