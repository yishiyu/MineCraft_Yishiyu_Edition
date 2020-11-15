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

    static sf::Clock timer;
    glm::vec3 lastPosition;

    // ��ǰ���ߵ�6�񷽿�
    for (Ray ray(m_player.position, m_player.rotation);
        ray.getLength() < 6;
        ray.step(0.1)){
        int x = ray.getEnd().x;
        int y = ray.getEnd().y;
        int z = ray.getEnd().z;

        auto block = m_world.getBlock(x, y, z);

        // �������������
        if (block != 0){
            // ��ȴʱ��0.2s
            if (timer.getElapsedTime().asSeconds() > 0.2){
                // �������,�Ƴ�����,��������
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    timer.restart();
                    m_world.editBlock(x, y, z, 0);
                    break;
                }
                // �Ҽ�����,���÷���,��������
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    timer.restart();
                    m_world.editBlock(lastPosition.x,
                        lastPosition.y,
                        lastPosition.z, 1);
                    break;
                }
            }
        }
        // ��¼���һ����������
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
