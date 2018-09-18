#include "Mesh.h"
#include <vector>
#include <iostream>
#include <string>

Mesh::Mesh(std::vector<VertexNoTexture> vertices, unsigned int numVertices, GLuint* vao)
{
	glBindVertexArray(*vao);
	glGenBuffers(1, &vertexArrayBuffer);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexNoTexture), &vertices.front(), GL_STATIC_DRAW)
		;
	//position every 2 floats   stride from beginning of attribute to beginning of another one , last element offset from the beginning of the array to find the attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);
	//color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 3));
	//UV
	//glEnableVertexAttribArray(2);
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 6));


	glBindVertexArray(0);
	//GLushort indices[] = { 0, 1, 2, 1,3,4, 1,4,8, 8,5,1, 4,3,8, 3,7,8, 1,2,6, 1,6,5, 2,3,7, 2,6,7, 5,6,7, 5,7,8};
	//glGenBuffers(1, &indexBufferID);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

Mesh::Mesh(GLuint* vao, std::vector<VertexNoTexture> vertices, unsigned int numVertices, std::vector<unsigned short> indices, int numIndices){

	glBindVertexArray(*vao);
	glGenBuffers(1, &vertexArrayBuffer);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexNoTexture), &vertices.front(), GL_STATIC_DRAW)
		;
	//position every 2 floats   stride from beginning of attribute to beginning of another one , last element offset from the beginning of the array to find the attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);
	//color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 3));

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 6));

	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)* numIndices, &indices.front(), GL_STATIC_DRAW);


}

Mesh::Mesh(GLuint* vao, int vertexData, int indexData){
	glBindVertexArray(*vao);
	glGenBuffers(1, &vertexArrayBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexNoTexture)* vertexData, NULL, GL_DYNAMIC_DRAW);
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err << std:: endl;
	}

	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)* indexData, NULL, GL_DYNAMIC_DRAW);
	GLenum err2;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err2 << std::endl;
	}

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);
	//color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 3));

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 6));

	//UV
}

Mesh::Mesh(GLuint* vao, int i){
	glBindVertexArray(*vao);
	glGenBuffers(1, &vertexArrayBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexNoTexture)* 1000, NULL, GL_STATIC_DRAW);
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err << std::endl;
	}

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);
	//color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 3));

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GL_FLOAT), (char*)(sizeof(GL_FLOAT)* 6));

	//UV
}

void Mesh::continua(GLuint* vao, std::vector<VertexNoTexture> vertices, unsigned int numVertices){
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);

	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(VertexNoTexture), &vertices.front());
	GLenum err1;
	while ((err1 = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err1 << std::endl;
	}

}

void Mesh::completeFilling(GLuint *vao, std::vector<unsigned short> indices, int numIndices){

	glBindVertexArray(*vao);
	//	glGenBuffers(1, &indexBufferID);
	//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);

	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, numIndices*sizeof(unsigned short), &indices.front());
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err << std::endl;
	}
}

void Mesh::drawElements(GLenum shape, int n, GLuint* VAO, std::vector<unsigned short> indices){

	glBindVertexArray(*VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glDrawElements(shape, n, GL_UNSIGNED_SHORT, 0);
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err << std::endl;
	}
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}


void Mesh::draw(GLenum shape, int n, GLuint* VAO){

	glBindVertexArray(*VAO);

	glDrawArrays(shape, 0, n);
}

void Mesh::drawDifferentElements(GLenum shape, int n, GLuint* VAO, std::vector<unsigned short> indices){

}


Mesh::~Mesh()
{
}
