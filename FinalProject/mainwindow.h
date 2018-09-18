#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <qsplitter.h>
#include "MyGLWidget.h"
#include "MyQtWidget.h"
#include "dialog.h"
#include "Leaf.h"
#include "settings.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	//manage movement with cursor

	void mouseMoveEvent(QMouseEvent* e);

	//manage keyboard input
	void keyPressEvent(QKeyEvent*);

	Point2D* fromQPointToPoint2D(QPoint qpoints[]);

	void emptyEverything();

	void settingsLeaf();

	void mergeLS();

	void settingsSurface();


	void fillLeftBorder();

	void fillRightBorder();

	QPoint* getLeftInputFor2D(){
		return leftInputFor2D;
	}

	QPoint* getRightInputFor2D(){
		return rightInputFor2D;
	}

	void setNumbers(float number[16]){
		for (int i = 0; i < 16; i++){
			numbers[i] = number[i];
		}
	}

	Point2D* getLeftInputFor3D(){
		return leftInputFor3D;
	}

	Point2D* getRightInputFor3D(){
		return rightInputFor3D;
	}

	float getXTransformed(float value);
	float getYTransformed(float value, float istart, float istop, float ostart, float ostop);


	std::vector<Point2D> flipY(std::vector<Point2D> points);



public slots:
	void on_actionSet_Points_triggered();
	void on_actionWireframe_On_triggered();
	void on_actionWireframe_Off_triggered();
	void on_actionSample_3_triggered();
	void on_actionSample_4_triggered();
	void on_actionSurface_1_triggered();
	void on_actionSurface_2_triggered();
	void on_actionMerge_triggered();
	void wireframeClicked();
	void pointsClicked();
	void lightClicked();
	void plyClicked();
	void surfaceClicked();
	void polygonClicked();

	void setVertices(std::vector<VertexNoTexture>& vert){
		leafVertices = vert;
	}

	void setIndices(std::vector<unsigned short>& ind){
		indices = ind;
	}

	void setNumtriangles(int n){
		numTriangles = n;
	}

	void setNumVertices(int n){
		numVertices = n;
	}





private:
	Ui::MainWindowClass ui;

	bool merge;
	int numVertices;
	int numTriangles;

	std::vector<VertexNoTexture> leafVertices;
	std::vector<unsigned short>indices;

	MyGLWidget *myGlWidget;
	MyQtWidget *myQtWidget;
	Settings* sett;

	bool leafReady;
	bool surfaceReady;
	bool okForOutput;
	bool running;

	Leaf* leaf;

	float numbers[16];

	QPoint leftInputFor2D[4];
	QPoint rightInputFor2D[4];

	Point2D leftInputFor3D[4];
	Point2D rightInputFor3D[4];

	Point3D matrix[4][4];

	std::vector<Point3D> surfPoints;


};

#endif // MAINWINDOW_H
