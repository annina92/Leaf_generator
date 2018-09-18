#include <assert.h>
#include "Point2D.h"
#include "Point3D.h"
#include "Camera.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"

#include <QtWidgets\qmouseeventtransition.h>
#include <QtWidgets\qkeyeventtransition.h>
#include <QtWidgets\qopenglwidget.h>
#include <QtGui\qevent.h>

#pragma once

class MyGLWidget : public QOpenGLWidget
{
public:
	MyGLWidget();
	~MyGLWidget();

	void init();


	//generate random points
	double random(int max, int min);

	//factorial of n
	int factorial(int n);

	//binomial coefficient
	float binomial_coefficient(int i, int n);

	//bernstein polinome
	float bernstein_polynomial(int i, int n, float u);

	//with this function, I map every point on border and inside the leaf on my surface
	Point3D mapPoint2DOnSurface(Point3D control_points_k[4][4], float u, float v);

	//draw 3 axes
	void drawX();
	void drawY();
	void drawZ();

	float getXTransformed(float value);
	float getYTransformed(float value, float istart, float istop, float ostart, float ostop);

	void getTransformedPoints(std::vector<Point2D>& points);

	void fillVertexVectorForDrawing(std::vector<Point2D>& points);

	Point3D draw_surface(Point3D control_points_k[4][4], float u, float v);

	std::vector<Point2D>& getLeafPoints(){
		return leafPoints;
	}

	std::vector<VertexNoTexture>& getPointsToDraw(){
		return leafVector;
	}

	void createMesh();


	Camera* getCamera(){
		return &camera;
	}

	void setIndices(std::vector<unsigned short>& vec){
		indices = vec;
	}

	void setNumIndices(int n){
		numIndices = n;
	}

	std::vector<VertexNoTexture> bezier_surface(Point3D pt[4][4]);

	void emptyIndices(){
		indices.clear();
	}

	void emptyIndicesSurface(){
		indicesSurface.clear();
	}

	void emptyLeafPoints(){
		leafPoints.clear();
	}
	void emptyPointsToDraw(){
		leafVector.clear();
	}

	void emptySurfaceVector(){
		surfaceVector.clear();
	}

	void emptyEverything(){
		emptyIndices();
		emptyLeafPoints();
		emptyPointsToDraw();
		emptyIndicesSurface();
	}

	void setWireframe(bool status){
		wireframe = status;
	}

	void findMin();
	void findMax();

	void fillX();
	void fillY();
	void fillZ();

	void fillVectorFromUShort(std::vector <unsigned short>& vertices_vector, GLushort* ind, int num);

	void createBoundingBox();

	void makePlane();
	void initSurface(std::vector<Point3D>& matrix);

	std::vector<VertexNoTexture> getNormal(std::vector<VertexNoTexture>& vectorr);

	void surface();


	void setLeafNormals();

	void initPointers();

	void makeBoundingBox();

	void countOccurrencies();

	void setPoints(bool p){
		points = p;
	}

	void setLight(float l){
		light = l;
	}

	int getNumVertices(){
		return leafVector.size();
	}

	int getNumIndices() {
		return numIndices;
	}

	std::vector<unsigned short> getIndices(){
		return indices;
	}

	void setIndicesSurface(std::vector<unsigned short> id){
		indicesSurface = id;
	}

	std::vector<VertexNoTexture> getVertices(){
		return leafVector;
	}

	void setPointsToDraw3D(std::vector<Point3D> pt){
		pointsToDraw3D = pt;

	}

	void setLeafVector(std::vector<VertexNoTexture>& lv){
		leafVector = lv;

	}

	void setSurfaceVector(std::vector<VertexNoTexture>& sv){
		surfaceVector = sv;
	}

	void getOutput(std::string s);

	void setSurfaceBool(bool status){
		surfaceBool = status;
	}
	void setPolygon(bool status){
		polygon = status;
	}

protected:
	void paintGL();
	void initializeGL();
	void resize();


private:

	bool polygon;
	float light = 0;
	bool points = false;
	bool surfaceBool;
	Mesh* Xaxis;
	Mesh* Yaxis;
	Mesh* Zaxis;
	Mesh* planeMesh;
	Mesh* leaf;
	Mesh* example;

	Mesh* box;

	GLuint *xAxisVAOptr;
	GLuint xAxisVAO;
	GLuint *yAxisVAOptr;
	GLuint yAxisVAO;
	GLuint *zAxisVAOptr;
	GLuint zAxisVAO;
	GLuint *leafVAOptr;
	GLuint leafVAO;
	GLuint* leafNormalVAOptr;
	GLuint leafNormalVAO;
	GLuint* surfaceVAOptr;
	GLuint surfaceVAO;

	GLuint* planeNormalVAOptr;
	GLuint planeNormalVAO;

	Mesh* planeNormalMesh;
	Mesh* leafNormalMesh;
	Mesh* surfaceMesh;

	GLuint *planeVAOptr;
	GLuint planeVAO;
	GLuint *boxVAOptr;
	GLuint boxVAO;

	GLuint *provaVAOptr;
	GLuint provaVAO;
	bool surfaceOk;

	Camera camera;
	Shader* shaderNoTexture;
	std::vector<unsigned short> indices;
	int numIndices;
	bool value = false;

	std::vector<VertexNoTexture>leafNormal;
	std::vector<VertexNoTexture>planeNormal;
	std::vector<Point2D> leafPoints;
	std::vector<VertexNoTexture> leafVector;
	std::vector<VertexNoTexture>boxVertices;
	std::vector<VertexNoTexture> planevertices;

	std::vector<unsigned short> indicesSurface;
	std::vector<VertexNoTexture> surfaceVector;

	void fill_vectorFromArray(std::vector <VertexNoTexture>& vertices_vector, Point3D vertices_array[], int numVertices);
	void fill_vectorFromArray(std::vector <VertexNoTexture>& vertices_vector, Point3D vertices_array[], int numVertices, int i);

	std::vector<unsigned short> boxIndices;
	std::vector<unsigned short> planeIndices;

	std::vector<Point3D> pointsToDraw3D;


	bool wireframe = false;

	float* min_xPtr;
	float* min_yPtr;
	float* min_zPtr;
	float* max_xPtr;
	float* max_yPtr;
	float* max_zPtr;

	GLuint boxIBO;

	float min_x;
	float min_y;
	float min_z;
	float max_x;
	float max_y;
	float max_z;

	float xCoord[300];
	float yCoord[300];
	float zCoord[300];

	Point3D surfaceForLeaf[4][4];

};
