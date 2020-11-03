//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_CAMERA_H
#define MINECRAFT_YISHIYU_EDITION_CAMERA_H

#include "Maths/glm.h"
#include "Entity.h"

// 游戏相机类
// 持有一个实体对象的指针,跟随这个实体运动和旋转
// 同时自身也是实体类的子类,继承实体类的两个属性
// 自身属性还有三个变换矩阵,可以通过update方法更新
class Camera : public Entity {
public:
    Camera();

    void update();
    void hookEntity(const Entity &entity);

    const glm::mat4 &getViewMatrix() const noexcept;

    const glm::mat4 &getProjMatrix() const noexcept;

    const glm::mat4 &getProjectionViewMatrix() const noexcept;


private:
    const Entity *m_pEntity;

    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_projViewMatrix;
};

#endif //MINECRAFT_YISHIYU_EDITION_CAMERA_H
