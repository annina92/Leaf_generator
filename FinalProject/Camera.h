#include <glm-0.9.2.7\glm\glm.hpp>
#include <string>
#include <glm-0.9.2.7\glm\gtx\transform.hpp>

class Camera
{

public:
	Camera();
	~Camera();
	void mouseUpdate(glm::vec2& newMousePosition);
	glm::mat4 getWorldToViewMatrix();
	void rotate();
	void translate(char direction);
	void translate(glm::vec3 position);



	void moveLeft(){
		glm::vec3 direction = glm::cross(viewDirection, UP);
		position += -MOV_SPEED*direction;
	}
	void moveRight(){
		glm::vec3 direction = glm::cross(viewDirection, UP);
		position += MOV_SPEED*direction;
	}
	void moveForward(){
		position += MOV_SPEED * viewDirection;
	}
	void moveBackward(){
		position += -MOV_SPEED * viewDirection;

	}
	void moveUp(){
		position += MOV_SPEED *UP;
	}
	void moveDown(){
		position += -MOV_SPEED*UP;
	}


private:
	glm::vec3 position;
	glm::vec3 viewDirection;
	const glm::vec3 UP;
	glm::vec2 oldMousePosition;
	glm::mat4 cameraPosition;
	const float MOV_SPEED = 0.1f;
	const float ROT_SPEED = 0.5f;


};
