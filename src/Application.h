//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_APPLICATION_H
#define MINECRAFT_YISHIYU_EDITION_APPLICATION_H

#include <vector>
#include <memory>

#include "States/StateBase.h"
#include "Renderer/RenderMaster.h"

#include "Context.h"
#include "Camera.h"

// 应用实例类
//
class Application {
public:
    Application(std::string &&name);

    void runLoop();

    // 接受一个左值对象,生成一个unique_ptr并存放到vector中
    template<typename T, typename... Args>
    void pushState(Args &&... args) {
        m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        //auto &s = m_states.back();
    }

    void popState();

private:
    void handleEvents();

    std::vector<std::unique_ptr<StateBase>> m_states;

    Context m_context;
    RenderMaster m_masterRenderer;


    bool m_isPopState = false;
    Camera m_camera;
};


#endif //MINECRAFT_YISHIYU_EDITION_APPLICATION_H
