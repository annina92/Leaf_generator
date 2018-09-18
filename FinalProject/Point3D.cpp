#include "Point3D.h"

Point3D::Point3D(){

}

Point3D::Point3D(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}
/*
void Point3D::drawPoint(){
	glDrawArrays(GL_POINT, 0, 1);
}*/


Point3D::~Point3D()
{
}
