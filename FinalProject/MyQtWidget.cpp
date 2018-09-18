#include "MyQtWidget.h"

MyQtWidget::MyQtWidget()
{

}

MyQtWidget::~MyQtWidget()
{

}

void MyQtWidget::getBezierValues(){

}

void MyQtWidget::updateLeftBorder(QPoint side[4]){
	for (int i = 0; i < 4; i++){
		left[i] = side[i];
	}
}

void MyQtWidget::updateRightBorder(QPoint side[4]){
	for (int i = 0; i < 4; i++){
		right[i] = side[i];
	}
}


float MyQtWidget::getXTransformed(float value){
	return value * 500;
}


float MyQtWidget::getYTransformed(float value, float istart, float istop, float ostart, float ostop){
	return (ostart + (ostop - ostart) * ((value - istart) / (istop - istart)));

}

void MyQtWidget::paintEvent(QPaintEvent* e){


	setMouseTracking(true);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	QPoint p1(250, 480);
	QPoint p2(10, 333);
	QPoint p3(200, 166);
	QPoint p4(250, 20);
	QPoint po[4]{p4, p3, p2, p1};



	QPoint p11(250, 480);
	QPoint p22(490, 333);
	QPoint p33(300, 166);
	QPoint p44(250, 20);
	QPoint po2[4]{p11, p22, p33, p44};


	QPainterPath path2;
	path2.moveTo(left[0]);
	path2.cubicTo(left[1], left[2], left[3]);

	QPainterPath path3;
	path3.moveTo(right[0]);
	path3.cubicTo(right[1], right[2], right[3]);



	painter.setPen(QPen(Qt::black, 4));
	painter.drawPath(path2);
	painter.drawPath(path3);

	for (int i = 0; i < randomPoints.size(); i++){
		QPoint p(getXTransformed(randomPoints[i].getX()), getYTransformed(randomPoints[i].getY(), 0, 1, 500, 0));
		painter.drawPoint(p);
	}
	//painter.drawPoint(QPoint(300, 70));

}

