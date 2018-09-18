#include "Leaf.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include "Point3D.h"
#include <assert.h>
#include "Vertex.h"
#include <fstream>

using glm::vec3;
using glm::vec2;
using glm::mat4;


//Leaf::Leaf()
//{
//}


Leaf::~Leaf()
{

}

void Leaf::readLeaf(std::string s){

	std::ifstream file(s);

	if (file.is_open()){
		for (int i = 0; i < 16; i++){
			file >> inputLeaf[i];
		}
	}
	file.close();

}


void Leaf::readSurface(std::string s){
	inputSurface.clear();
	std::ifstream file(s);

	float x, y, z;
	if (file.is_open()){

		for (int h = 0; h < 16; h++){
			file >> x;
			file >> y;
			file >> z;
			Point3D p(x, y, z);
			inputSurface.push_back(p);
		}
	}

	file.close();
}


void Leaf::updateLeftBorder(Point2D l[4]){
	for (int i = 0; i < 4; i++){
		left[i] = l[i];
	}
}

void Leaf::updateRightBorder(Point2D r[4]){
	for (int i = 0; i < 4; i++){
		right[i] = r[i];
	}
}

Point2D Leaf::drawBezier(Point2D pt[], double t) {


	double x = pow((1.0f - t), 3.0f) * pt[0].getX() + 3.0f * t * pow((1.0f - t), 2.0f) * pt[1].getX() + 3.0f * (1.0f - t) * pow(t, 2.0f)* pt[2].getX() + pow(t, 3.0f)* pt[3].getX();
	double y = pow((1.0f - t), 3.0f) * pt[0].getY() + 3.0f * t * pow((1.0f - t), 2.0f) * pt[1].getY() + 3.0f * (1.0f - t) * pow(t, 2.0f)* pt[2].getY() + pow(t, 3.0f)* pt[3].getY();

	Point2D p(x, y);
	return p;
}


int Leaf::pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
	int i, j, c = 0;
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((verty[i]>testy) != (verty[j]>testy)) &&
			(testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i]))
			c = !c;
	}
	return c;
}


void Leaf::fillXArray(){
	for (int i = 0; i < leafBorders.size(); i++){
		xBorders[i] = leafBorders[i].getX();
	}
}

void Leaf::fillYArray(){
	for (int i = 0; i < leafBorders.size(); i++){
		yBorders[i] = leafBorders[i].getY();
	}
}




float Leaf::randomNumber(int max, int min){

	return drand();

}

std::vector<Point2D> Leaf::fillBorders(){
	Point2D p;
	for (int i = 0; i < 50; i++){
		p = drawBezier(left, i / 50.0f);
		leafBorders.push_back(p);
	}

	for (int j = 0; j < 50; j++){
		p = drawBezier(right, j / 50.0f);
		leafBorders.push_back(p);
	}

	return leafBorders;
}


float Leaf::randomCoord(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
	return dis(gen);
}


void  Leaf::fillVectorOfLeafPoints(){

	int cont = 0;

	leafPoints = leafBorders;
	while (cont<200){
		float x = randomNumber(0.0f, 1.0f);
		float y = randomNumber(0.0f, 1.0f);
		Point2D p2(x, y);
		//100 IS border length
		if (pnpoly(100, xBorders, yBorders, p2.getX(), p2.getY()))
		{
			randomPoints.push_back(p2);
			leafPoints.push_back(p2);
			cont++;

		}
	}
}

void Leaf::fromVectorToFloat(std::vector<Point2D>& vect){
	int dim = vect.size();
	Point2D points[300];
	for (int i = 0; i < dim; i++){
		points[i].setX(vect[i].getX());
		points[i].setY(vect[i].getY());

	}

	int k = 0;
	int h = 0;
	while (k<600 && h<300){
		coordinates[k] = points[h].getX();
		coordinates[k + 1] = points[h].getY();
		k += 2;
		h++;
	}

}



void Leaf::getIndicesForTriangulation(){

	fromVectorToFloat(leafPoints);
	int* k;
	k = &numIndices;

	indices = getTriangleIndices(coordinates, dimPoints, k);

	for (int i = 0; i < numIndices; i++)
		indicesLeaf.push_back(indices[i]);

}

float Leaf::getXTransformed(float value){
	return value * 500;
}


float Leaf::getYTransformed(float value, float istart, float istop, float ostart, float ostop){
	return (ostart + (ostop - ostart) * ((value - istart) / (istop - istart)));

}

void Leaf::fillLeftBorder(){
	int j = 0;
	for (int i = 0; i < 4; i++){
		leftInputFor2D[i].setX(getXTransformed(inputLeaf[j]));
		left[i].setX(inputLeaf[j]);

		leftInputFor2D[i].setY(getYTransformed(inputLeaf[j + 1], 0, 1, 0, 500));
		left[i].setY(inputLeaf[j + 1]);

		j += 2;
	}

}

void Leaf::fillRightBorder(){
	int j = 8;
	for (int i = 0; i < 4; i++){
		rightInputFor2D[i].setX(getXTransformed(inputLeaf[j]));
		right[i].setX(inputLeaf[j]);

		rightInputFor2D[i].setY(getYTransformed(inputLeaf[j + 1], 0, 1, 0, 500));
		right[i].setY(inputLeaf[j + 1]);

		j += 2;
	}
}

void Leaf::initSurface(){

	int cont = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			surfaceForLeaf[i][j] = inputSurface[cont];
			cont++;
		}
	}


}

void Leaf::createSurfaceVector(){
	Point3D p;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			p = draw_surface(surfaceForLeaf, i / 100.0f, j / 100.0f);
			surfaceVector.push_back(VertexNoTexture{ vec3(p.getX(), p.getY(), p.getZ()), vec3(0.0f, 0.0f, 1.0f), vec3() });
		}
	}
}

void Leaf::triangulateSurface(){

	int run;
	for (int row = 0; row < 100; row++){
		for (int col = 0; col < 100; col++){
			indicesSurface.push_back(100 * row + col);
			indicesSurface.push_back(100 * row + col + 100);
			indicesSurface.push_back(100 * row + col + 100 + 1);

			indicesSurface.push_back(100 * row + col);
			indicesSurface.push_back(100 * row + col + 100 + 1);
			indicesSurface.push_back(100 * row + col + 1);
		}
	}


}
void Leaf::surfaceToDraw(){
	triangulateSurface();
	createSurfaceVector();
}

int Leaf::factorial(int n) {
	assert(n >= 0);
	int result = 1;
	for (int i = n; i > 1; i--)
		result *= i;
	return result;
}


float Leaf::binomial_coefficient(int i, int n) {
	assert(i >= 0); assert(n >= 0);
	return 1.0f * factorial(n) / (factorial(i) * factorial(n - i));
}


float Leaf::bernstein_polynomial(int i, int n, float u) {
	return binomial_coefficient(i, n) * powf(u, i) * powf(1 - u, n - i);
}


Point3D Leaf::draw_surface(Point3D control_points_k[4][4], float u, float v) {
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

void Leaf::fillVertexVectorForDrawing(std::vector<Point2D>& points){
	Point3D p;
	for (int i = 0; i < 300; i++){
		p = draw_surface(surfaceForLeaf, points[i].getY(), points[i].getX());
		pointsToDraw3D.push_back(Point3D{ p.getX(), p.getY(), p.getZ() });
		leafVector.push_back(VertexNoTexture{ vec3(p.getX(), p.getY(), p.getZ()), vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f) });
	}

}