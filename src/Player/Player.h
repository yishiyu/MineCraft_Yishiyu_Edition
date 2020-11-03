//
// Created by Yishiyu on 2020/11/2.
//

#ifndef MINECRAFT_YISHIYU_EDITION_PLAYER_H
#define MINECRAFT_YISHIYU_EDITION_PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Entity.h"

class Player : public Entity {
public:
    Player();

    void handleInput(const sf::RenderWindow &window);

    void update(float dt);

private:
    void keyboardInput();

    void mouseInput(const sf::RenderWindow &window);

    glm::vec3 m_velocity;
};


#endif //MINECRAFT_YISHIYU_EDITION_PLAYER_H
