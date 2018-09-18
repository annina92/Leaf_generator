#include "Camera.h"
#include <string>


Camera::Camera() :
viewDirection(0.0f, 0.0f, -1.0f),
UP(0.0f, 1.0f, 0.0f),
oldMousePosition(0.0f, 0.0f)
{
}

glm::mat4 Camera::getWorldToViewMatrix(){
	return 	glm::lookAt(position, position + viewDirection, UP);
}

void Camera::rotate(){
	//	position = translation * position;


}

void Camera::translate(glm::vec3 position){

}

void Camera::translate(char direction){
	switch (direction){
	case 'l':
		position.x = position.x - 0.1f;
		//viewDirection.x = viewDirection.x - 0.1f;
		break;
	case 'r':
		position.x = position.x + 0.1f;
		break;
	case 'u':
		position.y = position.y + 0.1f;
		break;
	case 'd':
		position.y = position.y - 0.1f;
		break;
	default:
		break;
	}
}


void Camera::mouseUpdate(glm::vec2& newMousePosition){

	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;

	if (glm::length(mouseDelta) > 50.0f)
	{
		oldMousePosition = newMousePosition;
		return;
	}
	glm::vec3 toRotateAroud = glm::cross(viewDirection, UP);

	viewDirection = glm::mat3(
		glm::rotate(-mouseDelta.x*ROT_SPEED, UP)*
		glm::rotate(-mouseDelta.y*ROT_SPEED, toRotateAroud))* viewDirection;

	oldMousePosition = newMousePosition;
}



Camera::~Camera()
{
}
