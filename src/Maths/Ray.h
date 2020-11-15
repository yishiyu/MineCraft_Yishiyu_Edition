// Created by Yishiyu on 2020/11/15.
//

#ifndef MINECRAFT_YISHIYU_EDITION_RAY_H
#define MINECRAFT_YISHIYU_EDITION_RAY_H

#include "glm.h"

// 射线类
// 有个起始位置有个终止位置
// 终止位置可以在direction上移动
class Ray{
public:
	Ray(const glm::vec3& position, const glm::vec3& direction);

	void step(float scale);

	const glm::vec3& getEnd() const;

	float getLength() const;

private:
	glm::vec3 m_rayStart;
	glm::vec3 m_rayEnd;
	glm::vec3 m_direction;
};


#endif //MINECRAFT_YISHIYU_EDITION_RAY_H