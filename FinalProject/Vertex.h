#ifndef VERTEX_H
#define VERTEX_H
#include <glm-0.9.2.7\glm\glm.hpp>


struct Vertex{
	glm::vec3 position;
};

struct VertexNoTexture{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;
};
#endif