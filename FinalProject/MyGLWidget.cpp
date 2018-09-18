#include "MyGLWidget.h"
#include <fstream>

using glm::vec3;
using glm::vec2;
using glm::mat4;

//points for leaf surface



Point3D pp1(0.0f, 0.0f, -1.5f);
Point3D pp2(1.0f, 0.0f, -1.5f);
Point3D pp3(2.0f, 0.0f, -1.5f);
Point3D pp4(3.0f, 0.0f, -1.5f);
Point3D pp5(0.0f, 0.0f, -0.5f);
Point3D pp6(1.0f, 0.0f, -0.5f);
Point3D pp7(2.0f, 0.0f, -0.5f);
Point3D pp8(3.0f, 0.0f, -0.5f);
Point3D pp9(0.0f, 0.0f, 0.5f);
Point3D pp10(1.0f, 0.0f, 0.5f);
Point3D pp11(2.0f, 0.0f, 0.5f);
Point3D pp12(3.0f, 0.0f, 0.5f);
Point3D pp13(0.0f, 0.0f, 1.5f);
Point3D pp14(1.0f, 0.0f, 1.5f);
Point3D pp15(2.0f, 0.0f, 1.5f);
Point3D pp16(3.0f, 0.0f, 1.5f);

Point3D plane[4][4]{
	{ pp1, pp2, pp3, pp4 },
	{ pp5, pp6, pp7, pp8 },
	{ pp9, pp10, pp11, pp12 },
	{ pp13, pp14, pp15, pp16 }
};




//VAO for meshes


//leaf
GLuint *leafVAOptr;
GLuint leafVAO;


MyGLWidget::MyGLWidget()
{
}


MyGLWidget::~MyGLWidget()
{
}


void MyGLWidget::init()
{

	glClearColor(0.19f, 0.3f, 0.47f, 0.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	surfaceOk = false;

}



void MyGLWidget::initSurface(std::vector<Point3D>& matrix){

	int cont = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			surfaceForLeaf[i][j] = matrix[cont];
			cont++;
		}
	}


}

double MyGLWidget::random(int max, int min){
	return ((double)rand() / (RAND_MAX + 1)) * (max - min + 1) + min;
}


int MyGLWidget::factorial(int n) {
	assert(n >= 0);
	int result = 1;
	for (int i = n; i > 1; i--)
		result *= i;
	return result;
}


float MyGLWidget::binomial_coefficient(int i, int n) {
	assert(i >= 0); assert(n >= 0);
	return 1.0f * factorial(n) / (factorial(i) * factorial(n - i));
}


float MyGLWidget::bernstein_polynomial(int i, int n, float u) {
	return binomial_coefficient(i, n) * powf(u, i) * powf(1 - u, n - i);
}


Point3D MyGLWidget::mapPoint2DOnSurface(Point3D control_points_k[4][4], float u, float v) {
	double x = 0.0f;
	double y = 0.0f;
	double z = 0.0f;

	for (int i = 0; i <4; i++) {
		for (int j = 0; j < 4; j++) {
			float poly_i = bernstein_polynomial(i, 3, u);
			float poly_j = bernstein_polynomial(j, 3, v);
			x += poly_i * poly_j * control_points_k[i][j].getX();
			y += poly_i * poly_j * control_points_k[i][j].getY();
			z += poly_i * poly_j * control_points_k[i][j].getZ();
		}
	}
	Point3D result(x, y, z);

	return result;
}


void MyGLWidget::drawX(){
	std::vector<VertexNoTexture> xAxis;

	xAxis.push_back(VertexNoTexture{ glm::vec3(0.0f, 0.0f, 0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	xAxis.push_back(VertexNoTexture{ glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	Xaxis = new Mesh(xAxis, 2, xAxisVAOptr);
}


void MyGLWidget::drawY(){
	std::vector<VertexNoTexture> yAxis;
	yAxis.push_back(VertexNoTexture{ glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	yAxis.push_back(VertexNoTexture{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	Yaxis = new Mesh(yAxis, 2, yAxisVAOptr);
}


void MyGLWidget::drawZ(){
	std::vector<VertexNoTexture> zAxis;
	zAxis.push_back(VertexNoTexture{ glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	zAxis.push_back(VertexNoTexture{ glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	Zaxis = new Mesh(zAxis, 2, zAxisVAOptr);

}


float MyGLWidget::getXTransformed(float value){
	return (value / 500);
}

//for y
//conversion of Processing function map float map(float value, float istart, float istop, float ostart, float ostop)
float MyGLWidget::getYTransformed(float value, float istart, float istop, float ostart, float ostop) {
	return (ostart + (ostop - ostart) * ((value - istart) / (istop - istart))) / 500;
}


void MyGLWidget::getTransformedPoints(std::vector<Point2D>& points){
	Point2D p;
	for (int i = 0; i < points.size(); i++){

		p.setX(points[i].getX());
		p.setY(points[i].getY());
		leafPoints.push_back(p);
	}
}


Point3D MyGLWidget::draw_surface(Point3D control_points_k[4][4], float u, float v) {
	double x = 0.0f;
	double y = 0.0f;
	double z = 0.0f;

	for (int i = 0; i <4; i++) {
		for (int j = 0; j < 4; j++) {
			float poly_i = bernstein_polynomial(i, 3, u);
			float poly_j = bernstein_polynomial(j, 3, v);
			x += poly_i * poly_j * control_points_k[i][j].getX();
			y += poly_i * poly_j * control_points_k[i][j].getY();
			z += poly_i * poly_j * control_points_k[i][j].getZ();
		}
	}
	Point3D result(x, y, z);

	return result;
}

void MyGLWidget::fillVertexVectorForDrawing(std::vector<Point2D>& points){
	Point3D p;
	for (int i = 0; i < 300; i++){
		p = draw_surface(surfaceForLeaf, points[i].getY(), points[i].getX());
		pointsToDraw3D.push_back(Point3D{ p.getX(), p.getY(), p.getZ() });
		leafVector.push_back(VertexNoTexture{ vec3(p.getX(), p.getY(), p.getZ()), vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f) });
	}
}


std::vector<VertexNoTexture> MyGLWidget::bezier_surface(Point3D pt[4][4]){
	int i = 0;
	int j = 0;
	std::vector<VertexNoTexture> vert;

	for (i = 0; i < 50; i++){
		for (j = 0; j < 50; j++){

			Point3D p = draw_surface(pt, i / 50.0f, j / 50.0f);
			vert.push_back(VertexNoTexture{ glm::vec3((float)p.getX(), (float)p.getY(), (float)p.getZ()), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
		}
	}

	//bezie = new Mesh(vert, 100, bezierVAO);
	return vert;
}

void MyGLWidget::fillX(){
	for (int i = 0; i < 300; i++){
		xCoord[i] = pointsToDraw3D[i].getX();
	}
}

void MyGLWidget::fillY(){
	for (int i = 0; i < 300; i++){
		yCoord[i] = pointsToDraw3D[i].getY();
	}
}

void MyGLWidget::fillZ(){
	for (int i = 0; i < 300; i++){
		zCoord[i] = pointsToDraw3D[i].getZ();
	}
}

void MyGLWidget::findMin(){
	float x = xCoord[0];
	for (int i = 1; i < 300; i++){
		if (xCoord[i] < x)
			x = xCoord[i];
	}

	*min_xPtr = x;

	float y = yCoord[0];
	for (int i = 1; i < 300; i++){
		if (yCoord[i] < y)
			y = yCoord[i];
	}

	*min_yPtr = y;

	float z = zCoord[0];
	for (int i = 1; i < 300; i++){
		if (zCoord[i] < z)
			z = zCoord[i];
	}

	*min_zPtr = z;


}

void MyGLWidget::findMax(){
	float x = xCoord[0];
	for (int i = 1; i < 300; i++){
		if (xCoord[i] > x)
			x = xCoord[i];
	}

	*max_xPtr = x;

	float y = yCoord[0];
	for (int i = 1; i < 300; i++){
		if (yCoord[i] > y)
			y = yCoord[i];
	}

	*max_yPtr = y;

	float z = zCoord[0];
	for (int i = 1; i < 300; i++){
		if (zCoord[i] > z)
			z = zCoord[i];
	}

	*max_zPtr = z;
}


void MyGLWidget::fill_vectorFromArray(std::vector <VertexNoTexture>& vertices_vector, Point3D vertices_array[], int numVertices){
	for (int i = 0; i < numVertices; i++){
		vertices_vector.push_back(VertexNoTexture{ glm::vec3((float)vertices_array[i].getX(), (float)vertices_array[i].getY(), (float)vertices_array[i].getZ()), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f) });

	}
}

void MyGLWidget::fill_vectorFromArray(std::vector <VertexNoTexture>& vertices_vector, Point3D vertices_array[], int numVertices, int color){
	for (int i = 0; i < numVertices; i++){
		vertices_vector.push_back(VertexNoTexture{ glm::vec3((float)vertices_array[i].getX(), (float)vertices_array[i].getY(), (float)vertices_array[i].getZ()), glm::vec3(0.3f, 0.28f, 0.02f), glm::vec3(0.0f, 1.0f, 0.0f) });

	}
}

void MyGLWidget::setLeafNormals(){
	for (int i = 0; i < indices.size(); i += 3){
		glm::vec3 u, v;
		glm::vec3 normal(0.0f, 0.0f, 0.0f);
		u = leafVector[indices[i + 1]].position - leafVector[indices[i]].position;
		v = leafVector[indices[i + 2]].position - leafVector[indices[i + 1]].position;

		normal.x = (u.y*v.z) - (u.z*v.y);
		normal.y = (u.z*v.x) - (u.x*v.z);
		normal.z = (u.x*v.y) - (u.y*v.x);

		if (normal.z < 0){

			u = leafVector[indices[i + 2]].position - leafVector[indices[i]].position;
			v = leafVector[indices[i]].position - leafVector[indices[i + 1]].position;

			normal.x = (u.y*v.z) - (u.z*v.y);
			normal.y = (u.z*v.x) - (u.x*v.z);
			normal.z = (u.x*v.y) - (u.y*v.x);

		}
		leafVector[indices[i]].normal = normal;
		leafVector[indices[i + 1]].normal = normal;
		leafVector[indices[i + 2]].normal = normal;

	}

}

void MyGLWidget::fillVectorFromUShort(std::vector <unsigned short>& vertices_vector, GLushort* ind, int num){
	for (int i = 0; i < num; i++){
		vertices_vector.push_back(ind[i]);
	}
}

void MyGLWidget::createBoundingBox(){
	fillX();
	fillY();
	fillZ();
	findMax();
	findMin();

}

void MyGLWidget::makePlane(){


	for (int i = 0; i < 4; i++)
		fill_vectorFromArray(planevertices, plane[i], 16, 1);
	//96 indices

	int run;
	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++){
			planeIndices.push_back(4 * row + col);
			planeIndices.push_back(4 * row + col + 4);
			planeIndices.push_back(4 * row + col + 4 + 1);

			planeIndices.push_back(4 * row + col);
			planeIndices.push_back(4 * row + col + 4 + 1);
			planeIndices.push_back(4 * row + col + 1);
		}
	}


}

void MyGLWidget::countOccurrencies(){
	std::vector<int> occ(300, 0);
	for (int i = 0; i < numIndices; i++){
		occ[indices[i]]++;
	}

}


void MyGLWidget::surface(){
	surfaceOk = true;



}
void MyGLWidget::createMesh(){


	value = true;
	createBoundingBox();
	leafNormal = getNormal(leafVector);

	countOccurrencies();
}

std::vector<VertexNoTexture> MyGLWidget::getNormal(std::vector<VertexNoTexture>& vectorr){
	std::vector<VertexNoTexture> result;

	for (int i = 0; i < vectorr.size(); i++){
		VertexNoTexture v1, v2;
		v1.position = vectorr[i].position;
		v1.color = vec3(1.0f, 1.0f, 1.0f);
		v1.normal = vec3(0.0f, 0.0f, 0.0f);
		v2.position = vectorr[i].position + vectorr[i].normal;
		v2.color = vec3(1.0f, 1.0f, 1.0f);
		v2.normal = vec3(0.0f, 0.0f, 0.0f);

		result.push_back(v1);
		result.push_back(v2);

	}

	return result;
}

void MyGLWidget::initPointers(){
	xAxisVAOptr = &xAxisVAO;
	glGenVertexArrays(1, xAxisVAOptr);

	yAxisVAOptr = &yAxisVAO;
	glGenVertexArrays(1, yAxisVAOptr);

	zAxisVAOptr = &zAxisVAO;
	glGenVertexArrays(1, zAxisVAOptr);

	min_xPtr = &min_x;
	min_yPtr = &min_y;
	min_zPtr = &min_z;

	max_xPtr = &max_x;
	max_yPtr = &max_y;
	max_zPtr = &max_z;

	surfaceVAOptr = &surfaceVAO;
	glGenVertexArrays(1, surfaceVAOptr);


	leafVAOptr = &leafVAO;
	glGenVertexArrays(1, leafVAOptr);

	boxVAOptr = &boxVAO;
	glGenVertexArrays(1, boxVAOptr);

	planeVAOptr = &planeVAO;
	glGenVertexArrays(1, planeVAOptr);

	planeNormalVAOptr = &planeNormalVAO;
	glGenVertexArrays(1, planeNormalVAOptr);

	leafNormalVAOptr = &leafNormalVAO;
	glGenVertexArrays(1, leafNormalVAOptr);
}

void MyGLWidget::makeBoundingBox(){

}

void MyGLWidget::initializeGL(){

	glewInit();
	init();
	initPointers();

	shaderNoTexture = new Shader("ShaderCode.glsl");
	shaderNoTexture->bind();



	//provaVAOptr = &provaVAO;
	//glGenVertexArrays(1, provaVAOptr);

	drawX();
	drawY();
	drawZ();

	makePlane();

	Point3D p1(-0.5, -0.5, -0.5);
	Point3D p2(0.5, -0.5, -0.5);
	Point3D p3(0.5, 0.5, -0.5);
	Point3D p4(-0.5, 0.5, -0.5);
	Point3D p5(-0.5, -0.5, 0.5);
	Point3D p6(0.5, -0.5, 0.5);
	Point3D p7(0.5, 0.5, 0.5);
	Point3D p8(-0.5, 0.5, 0.5);
	Point3D vertices[] = {
		p1, p2, p3, p4, p5, p6, p7, p8
	};

	fill_vectorFromArray(boxVertices, vertices, 8);

	planeNormal = getNormal(planevertices);


	GLushort ind[16] = {
		0, 1, 2, 3,
		4, 5, 6, 7,
		0, 4, 1, 5, 2, 6, 3, 7
	};

	fillVectorFromUShort(boxIndices, ind, 16);
	//std::vector<VertexNoTexture> exa = bezier_surface(surfaceForLeaf);
	//example = new Mesh(exa, exa.size(), provaVAOptr);
	box = new Mesh(boxVAOptr, 8, 16);
	planeMesh = new Mesh(planeVAOptr, planevertices, 16, planeIndices, 96);
	planeNormalMesh = new Mesh(planeNormal, planeNormal.size(), planeNormalVAOptr);
	//leafNormalMesh = new Mesh(leafNormalVAOptr, 1);
	surfaceMesh = new Mesh(surfaceVAOptr, 10000, 60000);

	leaf = new Mesh(leafVAOptr, 300, 1600);





}

void MyGLWidget::paintGL(){

	glViewport(0, 0, width(), height());
	vec3 lightPosition(1.5f, 0.3f, 1.5f);
	shaderNoTexture->lightValues(lightPosition, light);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 id(1.0f);
	glm::mat4 projectionMatrix = glm::perspective(60.0f, 4.0f / 3.0f, 0.1f, 10.0f);

	glm::mat4 scale = glm::scale(0.3f, 0.3f, 0.3f);

	glm::mat4 rot = glm::rotate(glm::mat4(), 40.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 fullMatrix = projectionMatrix* camera.getWorldToViewMatrix() *rot*scale;
	shaderNoTexture->passValues(fullMatrix, "fullMatrix");

	Xaxis->draw(GL_LINES, 2, xAxisVAOptr);

	Yaxis->draw(GL_LINES, 2, yAxisVAOptr);

	Zaxis->draw(GL_LINES, 2, zAxisVAOptr);

	planeMesh->drawElements(GL_TRIANGLES, 96, planeVAOptr, planeIndices);
	if (surfaceOk){
		surfaceMesh->continua(surfaceVAOptr, surfaceVector, surfaceVector.size());
		surfaceMesh->completeFilling(surfaceVAOptr, indicesSurface, indicesSurface.size());
	}
	if (surfaceBool){
		surfaceMesh->drawElements(GL_TRIANGLES, 60000, surfaceVAOptr, indicesSurface);
	}


	//planeNormalMesh->draw(GL_LINES, planeNormal.size(), planeNormalVAOptr);

	//	if (wireframe)
	//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//	else if (!wireframe)
	//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (value){

		//leafNormalMesh->continua(leafNormalVAOptr, leafNormal, 600);


		leaf->continua(leafVAOptr, leafVector, 300);
		leaf->completeFilling(leafVAOptr, indices, numIndices);
		box->continua(boxVAOptr, boxVertices, boxVertices.size());
		box->completeFilling(boxVAOptr, boxIndices, boxIndices.size());


		glm::vec3 size = glm::vec3(max_x - min_x, max_y - min_y, max_z - min_z);
		glm::vec3 center = glm::vec3((min_x + max_x) / 2, (min_y + max_y) / 2, (min_z + max_z) / 2);
		glm::mat4 transform = glm::translate(glm::mat4(1), center)* glm::scale(glm::mat4(1), size);
		glm::mat4 newOne = fullMatrix*transform;
		shaderNoTexture->passValues(newOne, "fullMatrix");
		//void Mesh::drawElements(GLenum shape, int n, GLuint* VAO, std::vector<unsigned short> indices){

		//box->drawElements(GL_LINE_LOOP, 16, boxVAOptr , boxIndices);
		glBindVertexArray(boxVAO);
		glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_SHORT, 0);
		glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_SHORT, (GLvoid*)(4 * sizeof(GLushort)));
		glDrawElements(GL_LINES, 8, GL_UNSIGNED_SHORT, (GLvoid*)(8 * sizeof(GLushort)));
		glBindVertexArray(0);

	}

	shaderNoTexture->passValues(fullMatrix, "fullMatrix");
	//leafNormalMesh->draw(GL_LINES, 600, leafNormalVAOptr);
	if (wireframe){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		leaf->drawElements(GL_TRIANGLES, (numIndices), leafVAOptr, indices);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	//else if (!wireframe)

	if (points)
		leaf->drawElements(GL_POINTS, (numIndices), leafVAOptr, indices);
	//else if (!points)
	if (polygon)
		leaf->drawElements(GL_TRIANGLES, (numIndices), leafVAOptr, indices);


}

void MyGLWidget::resize(){

}

