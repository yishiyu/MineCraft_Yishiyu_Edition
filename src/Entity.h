//
// Created by Yishiyu on 2020/11/2.
//

#ifndef MINECRAFT_YISHIYU_EDITION_ENTITY_H
#define MINECRAFT_YISHIYU_EDITION_ENTITY_H

#include "Maths/glm.h"

// 实体类
// 封装了一个实体的三维坐标和旋转角
class Entity{
public:
    glm::vec3 position;
    glm::vec3 rotation;
};

#endif //MINECRAFT_YISHIYU_EDITION_ENTITY_H
