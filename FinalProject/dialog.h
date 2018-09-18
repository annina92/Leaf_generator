#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialog.h"

class Dialog : public QDialog
{
	Q_OBJECT

public:
	Dialog(QWidget *parent = 0);
	~Dialog();

	QPoint* getLeft();
	QPoint* getRight();

	void updateSide(QPoint* p1, QPoint* p2, QPoint* p3, QPoint* p4, QPoint side[4]);

	void update(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7, QPoint p8);

	float* getCoord(){
		return coord;
	}

	void fromQPointToFloat();

//	int* getValues();

signals:

	
public slots :
	void checkValid();
	void on_pushButton_clicked();



private:
	Ui::Dialog ui;
	QLineEdit *Point1x;



//	QLineEdit *Point1y;
//	QLineEdit *Point2x;
//	QLineEdit *Point2y;
//	QLineEdit *Point3x;
//	QLineEdit *Point3y;
//	QLineEdit *Point4x;
//	QLineEdit *Point4y;
//	QLineEdit *Point5x;
//	QLineEdit *Point5y;
//	QLineEdit *Point6x;
//	QLineEdit *Point6y;
//	QLineEdit *Point7x;
//	QLineEdit *Point7y;
//	QLineEdit *Point8x;
//	QLineEdit *Point8y;

	QPoint* p1;
	QPoint* p2;
	QPoint* p3;
	QPoint* p4;
	QPoint* p5;
	QPoint* p6;
	QPoint* p7;
	QPoint* p8;

	//I'll store here the 8 control points for 2 bezier curve in anticlockwise order
	QPoint left[4];
	QPoint right[4];

	float coord[16];

	double a1		;
	double a2		;
	double a3		;
	double a4		;
	double a5 		;
	double a6 		;
	double a7 		;
	double a8 		;
	double a9 		;
	double a10		;
	double a11		;
	double a12		;
	double a13		;
	double a14		;
	double a15		;
	double a16;



};

#endif // DIALOG_H
