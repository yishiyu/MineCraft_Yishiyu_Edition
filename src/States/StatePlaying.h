//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H
#define MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H

#include "StateBase.h"
#include "../Player/Player.h"

// 游戏状态,继承自状态基类
// 持有一个Player对象
// 在初始化的时候设置Application对象的Camera对象跟随Player对象(Entity子类)
class StatePlaying : public StateBase {
public:
    StatePlaying(Application &app);

    void handleEvent(sf::Event e);

    void handleInput();

    void update(float deltaTime);

    void render(RenderMaster &renderer);

private:
    Player m_player;
};

#endif //MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H
