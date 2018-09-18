#include "settings.h"

Settings::Settings(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->setCheckable(true);
	ui.pushButton_2->setCheckable(true);
	ui.pushButton_3->setCheckable(true);
	ui.pushButton_5->setCheckable(true);
	ui.pushButton_6->setCheckable(true);

	polygon = true;
	surfaceBool = false;
	wireframe = false;
	points = false;
	light = 0;

	connect(ui.pushButton, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));

}

void Settings::on_pushButton_clicked(){
	if (ui.pushButton->isDown()||ui.pushButton->isChecked())
		wireframe = true;
	else if (!ui.pushButton->isDown() || !ui.pushButton->isChecked())
		wireframe = false;

}

void Settings::on_pushButton_2_clicked(){
	if (ui.pushButton_2->isDown() || ui.pushButton_2->isChecked())
		points = true;
	else if (!ui.pushButton_2->isDown() || !ui.pushButton_2->isChecked())
		points = false;
}

void Settings::on_pushButton_3_clicked(){

	if (ui.pushButton_3->isDown() || ui.pushButton_3->isChecked())
		light = 1;
	else if (!ui.pushButton_3->isDown() || !ui.pushButton_3->isChecked())
		light = 0;

}

void Settings::on_pushButton_4_clicked(){

}

void Settings::on_pushButton_5_clicked(){
	if (ui.pushButton_5->isDown() || ui.pushButton_5->isChecked())
		surfaceBool = true;
	else if (!ui.pushButton_5->isDown() || !ui.pushButton_5->isChecked())
		surfaceBool = false;

}

void Settings::on_pushButton_6_clicked(){
	if (ui.pushButton_6->isDown() || ui.pushButton_6->isChecked())
		polygon = true;
	else if (!ui.pushButton_6->isDown() || !ui.pushButton_6->isChecked())
		polygon = false;

}

void Settings::paintEvent(QPaintEvent* e){

}


Settings::~Settings()
{

}
