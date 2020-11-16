//
// Created by Yishiyu on 2020/11/1.
//

#include "StatePlaying.h"

#include "../Renderer/RenderMaster.h"
#include "../Application.h"
#include "../Maths/Ray.h"

StatePlaying::StatePlaying(Application &app)
        : StateBase(app) {
    app.getCamera().hookEntity(m_player);
}

void StatePlaying::handleEvent(sf::Event e) {

}

void StatePlaying::handleInput() {
    m_player.handleInput(m_pApplication->getWindow());

    int events = Events::NONE_EVENT;

    // 左键按下,移除方块,结束处理
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        events = Events::MOUSE_LEFT_DOWN;
    }
    // 右键按下,放置方块,结束处理
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        events = Events::MOUSE_RIGHT_DOWN;
    }
    // 
    else {
        return;
    }

    static sf::Clock timer;
    glm::vec3 lastPosition;

    // 当前视线的6格方块
    for (Ray ray(m_player.position, m_player.rotation);
        ray.getLength() < 6;
        ray.step(0.1)){
        int x = ray.getEnd().x;
        int y = ray.getEnd().y;
        int z = ray.getEnd().z;

        auto block = m_world.getBlock(x, y, z);

        // 不处理空气方块
        if (block != 0){
            // 冷却时间0.2s
            if (timer.getElapsedTime().asSeconds() > 0.2){

                // 处理事件
                switch (events){
                case Events::MOUSE_LEFT_DOWN:
                    timer.restart();
                    m_world.editBlock(x, y, z, 0);
                    break;
                case Events::MOUSE_RIGHT_DOWN:
                    timer.restart();
                    m_world.editBlock(lastPosition.x,
                        lastPosition.y,
                        lastPosition.z, 1);
                    break;
                default:
                    break;
                }
                break;
            }
        }
        // 记录最后一个空气方块
        lastPosition = ray.getEnd();
    }
}

void StatePlaying::update(float deltaTime) {
    m_player.update(deltaTime);
}

void StatePlaying::render(RenderMaster &renderer) {
//    renderer.drawQuad({0, 0, 0});
    renderer.drawCube({0, 0, 0});

//    renderer.drawCube({2, 0, 0});

//    renderer.drawCube({0, 2, 0});

    renderer.drawCube({0, 0, 2});
    m_world.renderWorld(renderer);
}
