#pragma once

#include <glm-0.9.2.7\glm\gtx\transform.hpp>
#include<glm-0.9.2.7\glm\glm.hpp>
using glm::vec3;
class Transform
{
public:
	Transform(const vec3& position = vec3(), const vec3& rotation = vec3(), const vec3& scale = vec3(1.0, 1.0, 1.0));


	inline glm::mat4 getModel() const {
		glm::mat4 positionMatrix = glm::translate(m_position);
		glm::mat4 rotationXMatrix = glm::rotate(m_rotation.x, vec3(1, 0, 0));
		glm::mat4 rotationYMatrix = glm::rotate(m_rotation.y, vec3(0, 1, 0));
		glm::mat4 rotationZMatrix = glm::rotate(m_rotation.z, vec3(0, 0, 1));
		glm::mat4 rotationMatrix = rotationZMatrix*rotationYMatrix*rotationXMatrix;
		glm::mat4 scaleMatrix = glm::scale(m_scale);

		return positionMatrix*rotationMatrix*scaleMatrix;

	}

	inline vec3& getPosition() { return m_position; }
	inline vec3& getRotation() { return m_rotation; }
	inline vec3& getScale() { return m_scale; }

	inline void setPosition(vec3& pos) { m_position = pos; }
	inline void setRotation(vec3& rot) { m_rotation = rot; }
	inline void setScale(vec3& scale) { m_scale = scale; }

	~Transform();
private:
	vec3 m_position;
	vec3 m_rotation;
	vec3 m_scale;
};

