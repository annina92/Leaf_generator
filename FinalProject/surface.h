#ifndef SURFACE_H
#define SURFACE_H

#include <QDialog>
#include "ui_surface.h"
#include "Point3D.h"

class surface : public QDialog
{
	Q_OBJECT

public:
	surface(QWidget *parent = 0);
	~surface();

	std::vector<Point3D> getMatrix(){
		return matrix;
	}


public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();


	
private:
	Ui::surface ui;

	std::vector<Point3D> matrix;
};

#endif // SURFACE_H
