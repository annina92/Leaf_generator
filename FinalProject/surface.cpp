#include "surface.h"
#include <fstream>
#include "Point3D.h"

surface::surface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void surface::on_pushButton_clicked(){
	std::ifstream file("sample_surface_1.txt");

	float x, y, z;
	if (file.is_open()){

		for (int h = 0; h < 16; h++){
				file >> x;
				file >> y;
				file >> z;
				Point3D p(x, y, z);
				matrix.push_back(p);
			
		}
	}

	file.close();
}

void surface::on_pushButton_2_clicked(){
	std::ifstream file("sample_surface_2.txt");

	float x, y, z;
	if (file.is_open()){

		for (int h = 0; h < 16; h++){
			file >> x;
			file >> y;
			file >> z;
			Point3D p(x, y, z);
			matrix.push_back(p);

		}
	}

	file.close();
}

surface::~surface()
{

}
