//
// 虽然名字叫Matrix,但是仅仅只是定义了一些关于的游戏相机类的矩阵操作
// 私以为这些函数定义到Camera类中更好一点,如果后续没有更有价值的东西需要加到这里,就改成Camera的成员函数
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_MATRIX_H
#define MINECRAFT_YISHIYU_EDITION_MATRIX_H

#include "glm.h"

// 游戏相机类
class Camera;

// 生成视图矩阵
glm::mat4 makeViewMatrix(const Camera& camera);

// 生成投影矩阵
glm::mat4 makeProjectionMatrix(float fov);

#endif //MINECRAFT_YISHIYU_EDITION_MATRIX_H
