//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_CAMERA_H
#define MINECRAFT_YISHIYU_EDITION_CAMERA_H

#include "Maths/glm.h"

// 游戏相机类
// 持有一个相机的世界坐标和一个旋转角度
// 自身属性还有三个变换矩阵,可以通过update方法更新
// 目前只能使用默认构造函数自带的默认属性,无法设置属性
// 默认属性为坐标:(0,0,-5),旋转(0,0,0)
class Camera {
public:
    Camera();

    void update();

    const glm::mat4 &getViewMatrix() const noexcept;

    const glm::mat4 &getProjMatrix() const noexcept;

    const glm::mat4 &getProjectionViewMatrix() const noexcept;

    const glm::vec3 &getPosition() const noexcept;

    const glm::vec3 &getRotation() const noexcept;

private:
    glm::vec3 m_worldPosition;
    glm::vec3 m_rotation;

    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_projViewMatrx;
};

#endif //MINECRAFT_YISHIYU_EDITION_CAMERA_H
