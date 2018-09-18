#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "ui_settings.h"

class Settings : public QWidget
{
	Q_OBJECT

public:
	Settings(QWidget *parent = 0);
	~Settings();

	bool getWireframe(){
		return wireframe;
	}

	bool getSurfaceBool(){
		return surfaceBool;
	}

	bool getPoints(){
		return points;
	}

	bool getPolygon(){
		return polygon;
	}

	float getLight(){
		return light;
	}

protected:
	void paintEvent(QPaintEvent* e);

signals:
	void buttonClicked();


public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();





private:
	Ui::Settings ui;
	bool wireframe;
	bool points;
	float light;
	bool surfaceBool;
	bool polygon;

};

#endif // SETTINGS_H
