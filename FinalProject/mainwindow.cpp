#include "mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>
#include "surface.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);

	QSplitter *splitter = new QSplitter(parent = 0);
	myGlWidget = new MyGLWidget();
	myQtWidget = new MyQtWidget();
	sett = new Settings();
	running = true;
	okForOutput = false;
	merge = false;

	setCentralWidget(splitter);
	splitter->addWidget(myQtWidget);
	splitter->addWidget(myGlWidget);
	splitter->addWidget(sett);
	leaf = new Leaf();

	connect(sett, SIGNAL(buttonClicked()), this, SLOT(wireframeClicked()));
	connect(sett, SIGNAL(buttonClicked()), this, SLOT(pointsClicked()));
	connect(sett, SIGNAL(buttonClicked()), this, SLOT(lightClicked()));
	connect(sett, SIGNAL(buttonClicked()), this, SLOT(plyClicked()));
	connect(sett, SIGNAL(buttonClicked()), this, SLOT(surfaceClicked()));
	connect(sett, SIGNAL(buttonClicked()), this, SLOT(polygonClicked()));



	//	splitter->addWidget();
}

void MainWindow::pointsClicked(){
	myGlWidget->setPoints(sett->getPoints());
}

void MainWindow::polygonClicked(){
	myGlWidget->setPolygon(sett->getPolygon());
}

void MainWindow::surfaceClicked(){
	myGlWidget->setSurfaceBool(sett->getSurfaceBool());
}

void MainWindow::wireframeClicked(){
	myGlWidget->setWireframe(sett->getWireframe());
}

void MainWindow::lightClicked(){
	myGlWidget->setLight(sett->getLight());
}

void MainWindow::plyClicked(){
	//if (okForOutput)
	//leaf->getOutput("leaf.ply");

}

void MainWindow::keyPressEvent(QKeyEvent* e){
	switch (e->key()){
	case Qt::Key::Key_W:
		myGlWidget->getCamera()->moveForward();
		repaint();
		break;
	case Qt::Key::Key_S:
		myGlWidget->getCamera()->moveBackward();
		repaint();

		break;
	case Qt::Key::Key_A:
		myGlWidget->getCamera()->moveLeft();
		repaint();

		break;
	case Qt::Key::Key_D:
		myGlWidget->getCamera()->moveRight();
		repaint();

		break;
	case Qt::Key::Key_R:
		myGlWidget->getCamera()->moveUp();
		repaint();

		break;
	case Qt::Key::Key_F:
		myGlWidget->getCamera()->moveDown();
		repaint();

		break;
	case Qt::Key::Key_Escape:
		exit(0);
		break;
	}
}


void MainWindow::mouseMoveEvent(QMouseEvent* e){
	myGlWidget->getCamera()->mouseUpdate(glm::vec2(e->x(), e->y()));
	repaint();
}



MainWindow::~MainWindow()
{

}


Point2D* MainWindow::fromQPointToPoint2D(QPoint qpoints[]){

	Point2D points[4];
	for (int i = 0; i < 4; i++){
		points[i].setX(qpoints[i].x());
		points[i].setY(qpoints[i].y());
	}
	return points;
}

void MainWindow::emptyEverything(){

	leaf->emptyEverything();

	myQtWidget->emptyEverything();

	myGlWidget->emptyEverything();
}


void MainWindow::on_actionWireframe_On_triggered(){
	myGlWidget->setWireframe(true);
}

void MainWindow::on_actionWireframe_Off_triggered(){
	myGlWidget->setWireframe(false);
}

float MainWindow::getXTransformed(float value){
	return value * 500;
}


float MainWindow::getYTransformed(float value, float istart, float istop, float ostart, float ostop){
	return (ostart + (ostop - ostart) * ((value - istart) / (istop - istart)));

}


void MainWindow::on_actionSample_3_triggered(){
	leaf->readLeaf("sample_1.txt");

	leaf->fillLeftBorder();
	leaf->fillRightBorder();
	settingsLeaf();
	if (merge)
		mergeLS();
}


void MainWindow::on_actionSample_4_triggered(){
	leaf->readLeaf("sample_2.txt");

	leaf->fillLeftBorder();
	leaf->fillRightBorder();
	settingsLeaf();
	if (merge)
		mergeLS();
}

void MainWindow::on_actionSurface_1_triggered(){
	surfPoints.clear();
	leaf->readSurface("sample_surface_1.txt");



	settingsSurface();
	if (merge)
		mergeLS();
}

void MainWindow::on_actionSurface_2_triggered(){
	surfPoints.clear();
	leaf->readSurface("sample_surface_2.txt");



	settingsSurface();
	if (merge)
		mergeLS();
}


std::vector<Point2D> MainWindow::flipY(std::vector<Point2D> points){
	for (int i = 0; i < points.size(); i++){
		points[i].setY(1 - points[i].getY());
	}
	return points;
}

void MainWindow::settingsSurface(){

	leaf->emptyIndicesSurface();
	leaf->emptSurfaceVector();
	leaf->initSurface();
	leaf->surfaceToDraw();

	myGlWidget->setIndicesSurface(leaf->getIndicesSurface());
	myGlWidget->setSurfaceVector(leaf->getSurfaceVector());

	myGlWidget->surface();

	surfaceReady = true;
}

void MainWindow::settingsLeaf(){

	leaf->emptyLeafPoints();
	leaf->emptyLeafBorders();
	leaf->emptyIndicesLeaf();
	leaf->emptyRandomPoints();
	leaf->emptyLeafVector();
	leaf->emptyPointToDraw3D();
	myQtWidget->emptyEverything();


	myQtWidget->updateLeftBorder(leaf->getLeftInputFor2D());
	myQtWidget->updateRightBorder(leaf->getRightInputFor2D());

	leaf->fillBorders();
	leaf->fillXArray();
	leaf->fillYArray();

	leaf->fillVectorOfLeafPoints();
	leaf->getIndicesForTriangulation();

	myQtWidget->setRandomPoints(flipY(leaf->getRandomPoints()));

	leafReady = true;

}

void MainWindow::mergeLS(){
	settingsLeaf();
	leaf->fillVertexVectorForDrawing(leaf->getLeafPoints());
	myGlWidget->setPointsToDraw3D(leaf->getPointsToDraw3D());
	myGlWidget->setLeafVector(leaf->getLeafVector());
	myGlWidget->setNumIndices(leaf->getNumIndices());
	myGlWidget->setIndices(leaf->getIndicesLeaf());
	//myGlWidget->setLeafNormals();

	myGlWidget->createMesh();

	setNumVertices(myGlWidget->getNumVertices());
	setIndices(myGlWidget->getIndices());
	setNumtriangles(myGlWidget->getNumIndices() / 3);
	setVertices(myGlWidget->getVertices());
	merge = true;
	okForOutput = true;
}

void MainWindow::on_actionMerge_triggered(){


	leaf->fillVertexVectorForDrawing(leaf->getLeafPoints());
	myGlWidget->setPointsToDraw3D(leaf->getPointsToDraw3D());
	myGlWidget->setLeafVector(leaf->getLeafVector());
	myGlWidget->setNumIndices(leaf->getNumIndices());
	myGlWidget->setIndices(leaf->getIndicesLeaf());
	//myGlWidget->setLeafNormals();

	myGlWidget->createMesh();

	setNumVertices(myGlWidget->getNumVertices());
	setIndices(myGlWidget->getIndices());
	setNumtriangles(myGlWidget->getNumIndices() / 3);
	setVertices(myGlWidget->getVertices());
	merge = true;
	okForOutput = true;
}

void MainWindow::on_actionSet_Points_triggered(){

	Dialog dialog;
	dialog.setModal(true);
	dialog.exec();
	emptyEverything();

	setNumbers(dialog.getCoord());


	settingsLeaf();

}
