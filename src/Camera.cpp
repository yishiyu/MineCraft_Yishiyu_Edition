//
// Created by Yishiyu on 2020/11/1.
//

#include "Camera.h"

#include "Maths/Matrix.h"

Camera::Camera() {
    m_projectionMatrix = makeProjectionMatrix(90);
    position = {0, 0, -3.5};
}

void Camera::update() {
    // 跟随hook的实体移动
    position = m_pEntity->position;
    rotation = m_pEntity->rotation;

    // 更新视图矩阵并重新计算投影视图矩阵
    m_viewMatrix = makeViewMatrix(*this);
    m_projViewMatrix = m_projectionMatrix * m_viewMatrix;
}

void Camera::hookEntity(const Entity &entity) {
    m_pEntity = &entity;
}

const glm::mat4 &Camera::getViewMatrix() const noexcept {
    return m_viewMatrix;
}

const glm::mat4 &Camera::getProjMatrix() const noexcept {
    return m_projectionMatrix;
}

const glm::mat4 &Camera::getProjectionViewMatrix() const noexcept {
    return m_projViewMatrix;
}
