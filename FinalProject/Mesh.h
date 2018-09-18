#include <gl\glew.h>
#include <vector>
#include <Vertex.h>

#pragma once
class Mesh
{
public:
	Mesh(GLuint* vao, int vertexData, int indexData);
	Mesh(GLuint* vao, int i);

	Mesh(std::vector<VertexNoTexture> vertices, unsigned int numVertices, GLuint* vao);
	Mesh(std::vector<VertexNoTexture> vertices, unsigned int numVertices, GLuint* vao, std::vector<int> indices, int numIndices);
	Mesh(GLuint* vao, std::vector<VertexNoTexture> vertices, unsigned int numVertices, std::vector<unsigned short> indices, int numIndices);

	~Mesh();
	void draw(GLenum shape, int n, GLuint* VAO);
	void drawElements(GLenum shape, int n, GLuint* VAO, std::vector<unsigned short> indices);
	void continua(GLuint* vao, std::vector<VertexNoTexture> vertices, unsigned int numVertices);
	void drawDifferentElements(GLenum shape, int n, GLuint* VAO, std::vector<unsigned short> indices);
	void completeFilling(GLuint *vao, std::vector<unsigned short> indices, int numIndices);

private:

	GLuint vertexArrayBuffer;
	GLuint indexBufferID;

	Mesh(const Mesh& other);
};

