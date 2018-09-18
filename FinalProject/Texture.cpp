#include "Texture.h"
#include "stb_image.h"
#include <fstream>
#include <cassert>
#include <iostream>


Texture::Texture(const std::string& fileName)
{
	int widht, height, numComponents;

	unsigned char* imageData = stbi_load(fileName.c_str(), &widht, &height, &numComponents, 4);
	if (imageData == NULL)
		std::cerr << "Texture loading failed";

	glGenTextures(1, &textureBuffer);
	glBindTexture(GL_TEXTURE_2D, textureBuffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widht, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}


void Texture::bind(unsigned int unit){

	assert(unit >= 0 && unit <= 31);
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, textureBuffer);


}

Texture::~Texture()
{
	glDeleteTextures(1, &textureBuffer);
}
