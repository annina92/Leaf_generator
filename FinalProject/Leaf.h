
#include <vector>

#include "Point2D.h"
#include "tricall.h"
#include "mtrand.h"
#include "Point3D.h"
#include "Vertex.h"
#include <qpoint.h>



#pragma once
class Leaf
{
public:
	Leaf() {};
	~Leaf();

	void updateLeftBorder(Point2D l[4]);
	void updateRightBorder(Point2D r[4]);

	void  Leaf::fillVectorOfLeafPoints();

	Point2D drawBezier(Point2D pt[], double t);

	float randomNumber(int max, int min);

	int pnpoly(int nvert, float *vertx, float *verty, float testx, float testy);

	void fillXArray();
	void fillYArray();

	std::vector<Point2D> fillBorders();

	void getIndicesForTriangulation();

	void fromVectorToFloat(std::vector<Point2D>& vect);

	float randomCoord();

	void fillVertexVectorForDrawing(std::vector<Point2D>& points);

	Point3D draw_surface(Point3D control_points_k[4][4], float u, float v);

	int factorial(int n);

	float binomial_coefficient(int i, int n);

	float bernstein_polynomial(int i, int n, float u);

	QPoint* getLeftInputFor2D(){
		return leftInputFor2D;
	}

	QPoint* getRightInputFor2D(){
		return rightInputFor2D;
	}

	void fillLeftBorder();

		void fillRightBorder();
	void initSurface();
	//	std::vector<Point2D>& getLeafPoints(){
	//		return leafPoints;
	//	}

	void addPoint2DtoLeafPoints(Point2D p){
		leafPoints.push_back(p);
	}

	std::vector<Point2D>& getLeafPoints(){
		return leafPoints;
	}

	std::vector<VertexNoTexture>& getLeafVector(){
		return leafVector;
	}

	std::vector<VertexNoTexture>& getSurfaceVector(){
		return surfaceVector;
	}

	std::vector<Point3D>& getPointsToDraw3D(){
		return pointsToDraw3D;
	}

	std::vector<Point2D>& getRandomPoints(){
		return randomPoints;
	}

	unsigned short* getIndices(){
		return indices;
	}

	void surfaceToDraw();
	void createSurfaceVector();

	void triangulateSurface();


	int getNumIndices(){
		return numIndices;
	}

	std::vector<unsigned short>& getIndicesLeaf(){
		return indicesLeaf;
	}

	std::vector<unsigned short>& getIndicesSurface(){
		return indicesSurface;
	}

	void createSurface();

	void emptyRandomPoints(){
		randomPoints.clear();
	}

	void emptyLeafVector(){
		leafVector.clear();
	}

	void emptSurfaceVector(){
		surfaceVector.clear();
	}
	void emptyLeafPoints(){
		leafPoints.clear();
	}
	void emptyLeafBorders(){
		leafBorders.clear();
	}
	void emptyIndicesLeaf(){
		indicesLeaf.clear();
	}

	void emptyIndicesSurface(){
		indicesSurface.clear();
	}

	void emptyPointToDraw3D(){
		pointsToDraw3D.clear();
	}

	void emptyEverything(){

		emptyLeafPoints();
		emptyLeafBorders();
		emptyIndicesLeaf();
		emptyRandomPoints();
		emptyLeafVector();
		emptyIndicesSurface();
		emptSurfaceVector();
	}

	void readLeaf(std::string s);
	void readSurface(std::string s);
	void getOutput(std::string s);
	float getYTransformed(float value, float istart, float istop, float ostart, float ostop);
	float getXTransformed(float value);



private:

	std::vector<Point2D> leafPoints;
	std::vector<Point2D> randomPoints;

	Point3D surfaceForLeaf[4][4];
	std::vector<Point3D> pointsToDraw3D;
	std::vector<VertexNoTexture> leafVector;
	std::vector<VertexNoTexture> surfaceVector;


	std::vector<Point2D> leafBorders;
	std::vector<unsigned short> indicesSurface;

	std::vector<Point3D> inputSurface;
	float inputLeaf[16];

	QPoint leftInputFor2D[4];
	QPoint rightInputFor2D[4];

	Point2D leftInputFor3D[4];
	Point2D rightInputFor3D[4];


	std::vector<unsigned short> indicesLeaf;
	Point2D left[4];
	Point2D right[4];

	MTRand drand;

	int numIndices;
	unsigned short* indices;

	float xBorders[100];
	float yBorders[100];

	int dimPoints = 300;
	float coordinates[600];
};

