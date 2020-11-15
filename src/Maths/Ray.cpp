// Created by Yishiyu on 2020/11/15.
//

#include "Ray.h"

Ray::Ray(const glm::vec3& position, const glm::vec3& direction)
	: m_rayStart(position)
	, m_rayEnd(position)
	, m_direction(direction){

}

void Ray::step(float scale){
	// ƫ����
	float yaw = glm::radians(m_direction.y + 90);
	// ������
	float pitch = glm::radians(m_direction.x);

	auto& p = m_rayEnd;

	p.x += glm::cos(pitch) * glm::cos(yaw) * scale;
	p.z += glm::cos(pitch) * glm::sin(yaw) * scale;
	p.y -= glm::sin(pitch) * scale;
}

const glm::vec3& Ray::getEnd() const{
	return m_rayEnd;
}

float Ray::getLength() const{
	return glm::distance(m_rayStart, m_rayEnd);
}
