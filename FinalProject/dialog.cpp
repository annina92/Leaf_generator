#include "dialog.h"

Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	p1 = new QPoint(0, 0);
	p2 = new QPoint(0, 0);
	p3 = new QPoint(0, 0);
	p4 = new QPoint(0, 0);
	p5 = new QPoint(0, 0);
	p6 = new QPoint(0, 0);
	p7 = new QPoint(0, 0);
	p8 = new QPoint(0, 0);


}

Dialog::~Dialog()
{

}



/*int* Dialog::getValues(){
	
	QString s1 = Point1x->text();
	QString s2= Point1y->text();
	QString s3= Point2x->text();
	QString s4= Point2y->text();
	QString s5= Point3x->text();
	QString s6= Point3y->text();
	QString s7= Point4x->text();
	QString s8= Point4y->text();
	QString s9= Point5x->text();
	QString s10= Point5y->text();
	QString s11 = Point6x->text();
	QString s12 = Point6y->text();
	QString s13 = Point7x->text();
	QString s14 = Point7y->text();
	QString s15 = Point8x->text();
	QString s16 = Point8y->text();

	int i1 = s1.toInt();
	int i2 = s2.toInt();
	int i3 = s3.toInt();
	int i4= s4.toInt();
	int i5 = s5.toInt();
	int i6 = s6.toInt();
	int i7 = s7.toInt();
	int i8 = s8.toInt();
	int i9 = s9.toInt();
	int i10 = s10.toInt();
	int i11 = s11.toInt();
	int i12 = s12.toInt();
	int i13 = s13.toInt();
	int i14 = s14.toInt();	
	int i15 = s15.toInt();
	int i16 = s16.toInt();

	QPoint* p1 = new QPoint(i1, i2);
	QPoint* p2 = new QPoint(i3, i4);
	QPoint* p3 = new QPoint(i5, i6);
	QPoint* p4= new QPoint(i7, i8);
	QPoint* p5= new QPoint(i9, i10);
	QPoint* p6= new QPoint(i11, i12);
	QPoint* p7 = new QPoint(i13, i14);
	QPoint* p8= new QPoint(i15, i16);










}
*/

void Dialog::on_pushButton_clicked()
{
	
	a1 = ui.Point1x->text().toDouble();
	a2=ui.Point1y->text().toDouble();
	a3=ui.Point2x->text().toDouble();
	a4=ui.Point2y->text().toDouble();
	a5=ui.Point3x->text().toDouble();
	a6=ui.Point3y->text().toDouble();
	a7=ui.Point4x->text().toDouble();
	a8=ui.Point4y->text().toDouble();
	a9=ui.Point5x->text().toDouble();
	a1=ui.Point5y->text().toDouble();
	a11=ui.Point6x->text().toDouble();
	a12=ui.Point6y->text().toDouble();
	a13=ui.Point7x->text().toDouble();
	a14=ui.Point7y->text().toDouble();
	a15=ui.Point8x->text().toDouble();
	a16=ui.Point8y->text().toDouble();

	fromQPointToFloat();
	//update(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8);
	//
	//updateSide(p1, p2, p3, p4, left);
	//updateSide(p5, p6, p7, p8, right);


	this->accepted();

}

void Dialog::fromQPointToFloat(){
	coord[0] = (float)a1;
	coord[1] = (float)a2;
	coord[2] = (float)a3;
	coord[3] = (float)a4;
	coord[4] = (float)a5;
	coord[5] = (float)a6;
	coord[6] = (float)a7;
	coord[7] = (float)a8;
	coord[8] = (float)a9;
	coord[9] = (float)a10;
	coord[10] = (float)a11;
	coord[11] = (float)a12;
	coord[12] = (float)a13;
	coord[13] = (float)a14;
	coord[14] = (float)a15;
	coord[15] = (float)a16;
}

void Dialog::update(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7, QPoint p8){
	updateSide(&p1, &p2, &p3, &p4, left);
	updateSide(&p5, &p6, &p7, &p8, right);

}
void Dialog::updateSide(QPoint* p1, QPoint* p2, QPoint* p3, QPoint* p4, QPoint side[4]){
	side[0] = *p1;
	side[1] = *p2;
	side[2] = *p3;
	side[3] = *p4;
}




QPoint* Dialog::getLeft(){
	return left;
}

QPoint* Dialog::getRight(){
	return right;
}


void Dialog::checkValid(){
	QValidator *validator = new QIntValidator(100, 999, this);

//Point1x->setValidator(validator);
//Point1y->setValidator(validator);
//Point2x->setValidator(validator);
//Point2y->setValidator(validator);
//Point3x->setValidator(validator);
//Point3y->setValidator(validator);
//Point4x->setValidator(validator);
//Point4y->setValidator(validator);
//Point5x->setValidator(validator);
//Point5y->setValidator(validator);
//Point6x->setValidator(validator);
//Point6y->setValidator(validator);
//Point7x->setValidator(validator);
//Point7y->setValidator(validator);
//Point8x->setValidator(validator);
//Point8y->setValidator(validator);

}