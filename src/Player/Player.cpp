//
// Created by Yishiyu on 2020/11/2.
//

#include "Player.h"

#include <SFML/Graphics.hpp>

Player::Player() {
    position = {0, 0, -5};
}

void Player::handleInput(const sf::RenderWindow &window) {
    keyboardInput();
    mouseInput(window);
}

void Player::update(float dt) {
    // 1. 根据自身速度移动坐标
    position += m_velocity * dt;
    // 2. 衰减速度至95%
    m_velocity *= 0.95;
}

void Player::keyboardInput() {
    // 速度向量
    glm::vec3 change;
    float speed = 0.5;

    // rotation初始化为(0,0,0),初始视角视为朝向(0,0,1)
    // OpenGL 中的坐标系为左手坐标系
    // 综上,(rotation.y+90)为当前朝向与世界x轴的夹角
    // 四个键可能以各种组合结果按下,所以用连续的if代替switch,结合+=可以实现多按键
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        change.x += glm::cos(glm::radians(rotation.y + 90)) * speed;
        change.z += glm::sin(glm::radians(rotation.y + 90)) * speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        change.x += -glm::cos(glm::radians(rotation.y + 90)) * speed;
        change.z += -glm::sin(glm::radians(rotation.y + 90)) * speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        change.x += glm::cos(glm::radians(rotation.y)) * speed;
        change.z += glm::sin(glm::radians(rotation.y)) * speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        change.x += -glm::cos(glm::radians(rotation.y)) * speed;
        change.z += -glm::sin(glm::radians(rotation.y)) * speed;
    }

    // 当前的速度向量加上计算出的速度改变向量
    m_velocity += change;
}

void Player::mouseInput(const sf::RenderWindow &window) {
    // 设置视角最高为80度
    static auto const BOUND = 80;
    // 使用鼠标移动量移动视角
    static auto lastMousePosition = sf::Mouse::getPosition(window);
    auto change = sf::Mouse::getPosition() - lastMousePosition;

    // 左右移动是绕y轴旋转,改变欧拉角中的偏航角(yaw)
    // 上下移动是绕x轴旋转,改变欧拉角中的俯仰角(pitch)
    // 滚转角(roll)不考虑(歪头时按理来说会改变滚转角)
    rotation.y += change.x * 0.05;
    rotation.x += change.y * 0.05;

    // 调整欧拉角,使其在指定范围内
    if (rotation.x > BOUND) rotation.x = BOUND;
    else if (rotation.x < -BOUND) rotation.x = -BOUND;

    if (rotation.y > 360) rotation.y = 0;
    else if (rotation.y < 0) rotation.y = 360;

    // 鼠标停留在屏幕正中央
    // 其实在Context初始化的时候鼠标就已经设置不可见了
    // 设置这个主要是为了不让鼠标飞出去
    auto cx = static_cast<int>(window.getSize().x / 2);
    auto cy = static_cast<int>(window.getSize().y / 2);
    sf::Mouse::setPosition({cx, cy}, window);

    // 记录鼠标位置
    lastMousePosition = sf::Mouse::getPosition();
}

