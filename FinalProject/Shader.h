#pragma once
#include <string>
#include <gl\glew.h>
#include "Transform.h"
#include <glm-0.9.2.7\glm\gtx\transform.hpp>
#include<glm-0.9.2.7\glm\glm.hpp>


class Shader
{
public:
	Shader(const std::string& filename);

	void bind();
	void update(const Transform& transform);
	void passValues(glm::mat4 matr, const GLchar* matrix);

	bool checkProgramStatus(GLuint program);
	bool checkShaderStatus(GLuint shader);
	GLuint createShader(const std::string& text, GLenum shaderType);
	std::string loadShader(const std::string& fileName);
	void lightValues(glm::vec3 light, float lightIsOn);
	~Shader();

private:
	Shader(const Shader& other){}
	void operator= (const Shader& other);
	enum {
		POSITION_UNIF,
		BUFFER_LIMIT
	};

	GLuint bufferUniform[BUFFER_LIMIT];

	GLuint programID;
	GLint baseImageLoc;
	GLuint shaders[2];

};

