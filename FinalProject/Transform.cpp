#include "Transform.h"


Transform::Transform(const vec3& position, const vec3& rotation, const vec3& scale)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}


Transform::~Transform()
{
}
