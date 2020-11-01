//
// Created by Administrator on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H
#define MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H

#include "StateBase.h"

class StatePlaying : public StateBase {
public:
    StatePlaying(Application &app);

    void handleEvent(sf::Event e);

    void handleInput();

    void update(float deltaTime);

    void render(RenderMaster &renderer);

private:
};

#endif //MINECRAFT_YISHIYU_EDITION_STATEPLAYING_H
