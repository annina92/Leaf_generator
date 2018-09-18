#include "mainwindow.h"
#include "MyGLWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;



	w.setFixedSize(1300, 550);
	w.show();
	return a.exec();
}
