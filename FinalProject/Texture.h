#pragma once
#include <string>
#include <gl\glew.h>
class Texture
{
public:
	Texture(const std::string& fileName);
	~Texture();
	void bind(unsigned int unit);

	GLuint textureBuffer;

};

