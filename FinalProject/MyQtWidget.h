
#include <QtWidgets/QMainWindow>
#include <QtGui\qpainter.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qinputdialog.h>
#include <QtWidgets\qdirmodel.h>
#include <QtGui\qpaintdevice.h>
#include "Point2D.h"


class MyQtWidget : public QWidget
{
	Q_OBJECT

public:
	MyQtWidget();
	~MyQtWidget();

	void updateLeftBorder(QPoint side[4]);
	void updateRightBorder(QPoint side[4]);

	float getYTransformed(float value, float istart, float istop, float ostart, float ostop);
	float getXTransformed(float value);


	void emptyRandomPoints(){
		randomPoints.clear();
	}

	void emptyEverything(){
		emptyRandomPoints();
	}

	void setRandomPoints(std::vector<Point2D>& rand){
		randomPoints = rand;
	}

	void flipY(QPoint points[4]);

private:
	QPoint left[4];
	QPoint right[4];
	bool firstUpdated = false;
	std::vector<Point2D> randomPoints;


signals:
	//on_PushButton_clicked();

	public slots :
		void getBezierValues();



protected:
	void paintEvent(QPaintEvent* e);

};

