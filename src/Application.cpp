//
// Created by Yishiyu on 2020/11/1.
//

#include "Application.h"

#include "States/StatePlaying.h"


Application::Application(std::string &&name) {
    // 使用当前Application生成一个StatePlaying
    // 并直接把这个对象压到状态栈中
    pushState<StatePlaying>(*this);
}

void Application::runLoop() {
    sf::Clock dtTimer;

    while (m_context.window.isOpen() && !m_states.empty()) {
        // 获取自上一次定时器归零后的deltaTime并把定时器归零
        auto deltaTime = dtTimer.restart();
        auto &state = *m_states.back();

        state.handleInput();
        state.update(deltaTime.asSeconds());
        m_camera.update();

        state.render(m_masterRenderer);
        m_masterRenderer.finishRender(m_context.window, m_camera);

        handleEvents();
        if (m_isPopState) {
            m_isPopState = false;
            m_states.pop_back();
        }
    }
}

void Application::handleEvents() {
    sf::Event e;
    while (m_context.window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                m_context.window.close();
                break;

            case sf::Event::KeyPressed:
                switch (e.key.code) {
                    case sf::Keyboard::Escape:
                        m_context.window.close();
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}


void Application::popState() {
    m_isPopState = true;
}
