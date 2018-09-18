#include "Shader.h"
#include <fstream>
#include <iostream>
#include <glm-0.9.2.7\glm\gtc\matrix_transform.hpp>
#include <glm-0.9.2.7\glm\gtc\type_ptr.hpp>




bool Shader::checkShaderStatus(GLuint shader)
{
	GLint compileStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE)
	{
		GLint infoLogLenght;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLenght);
		GLchar* buffer = new GLchar[infoLogLenght];
		GLsizei bufferSize;
		glGetShaderInfoLog(shader, infoLogLenght, &bufferSize, buffer);
		std::cout << buffer << std::endl;
		delete[] buffer;
		return false;
	}

	return true;

}

bool Shader::checkProgramStatus(GLuint program)
{
	GLint linkStatus;
	glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE)
	{
		GLint infoLogLenght;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLenght);
		GLchar* buffer = new GLchar[infoLogLenght];
		GLsizei bufferSize;
		glGetProgramInfoLog(program, infoLogLenght, &bufferSize, buffer);
		std::cout << buffer << std::endl;
		delete[] buffer;
		return false;
	}
	return true;

}

std::string Shader::loadShader(const std::string& fileName){
	std::ifstream file(fileName);
	if (!file.good())
	{
		std::cerr << "Couldn't open file";
		exit(1);
	}

	return std::string(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>());
}

GLuint Shader::createShader(const std::string& shaderStringText, GLenum shaderType){
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0)
		std::cerr << "error creation shader failed";
	const GLchar* shaderString;
	shaderString = shaderStringText.c_str();

	glShaderSource(shader, 1, &shaderString, 0);
	glCompileShader(shader);

	if (!checkShaderStatus(shader))
		std::cerr << "error!!!";

	return shader;
}


Shader::Shader(const std::string& fileName)
{
	programID = glCreateProgram();
	shaders[0] = createShader(loadShader("VertexNoTexture" + fileName), GL_VERTEX_SHADER);
	shaders[1] = createShader(loadShader("FragmentNoTexture" + fileName), GL_FRAGMENT_SHADER);

	for (int i = 0; i < 2; i++)
		glAttachShader(programID, shaders[i]);

	//	glBindAttribLocation(programID, 0, "position");
	//	glBindAttribLocation(programID, 1, "vertexColor");
	//	glBindAttribLocation(programID, 2, "UVTexture");

	glLinkProgram(programID);

	if (!checkProgramStatus(programID))
		return;


	//	baseImageLoc = glGetUniformLocation(programID, "tex");

	bufferUniform[POSITION_UNIF] = glGetUniformLocation(programID, "transform");
}



Shader::~Shader()
{
	for (int i = 0; i < 2; i++){
		glDetachShader(programID, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	glDeleteProgram(programID);
}

void Shader::bind(){

	glUseProgram(programID);
	//	glUniform1i(baseImageLoc, 0); //Texture unit 0 is for base images.
}

void Shader::update(const Transform& transform){
	glm::mat4 model = transform.getModel();
	glUniformMatrix4fv(bufferUniform[POSITION_UNIF], 1, GL_FALSE, &model[0][0]);
}

void Shader::lightValues(glm::vec3 light, float ligthIsOn){
	GLuint lightPositionUniformLocation = glGetUniformLocation(programID, "lightPosition");
	GLuint lightIsOnPositionUniformLocation = glGetUniformLocation(programID, "lightIsOn");
	glUniform3f(lightPositionUniformLocation, 1, GL_FALSE, light[0]);
	glUniform1f(lightIsOnPositionUniformLocation, ligthIsOn);
}

void Shader::passValues(glm::mat4 matr, const GLchar* matrix){
	//glBufferData(GL_ARRAY_BUFFER, sizeof(matrix), matrix, GL_DYNAMIC_DRAW);
	GLint modelLoc = glGetUniformLocation(programID, matrix);
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &matr[0][0]);

}
