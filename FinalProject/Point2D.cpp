#include "Point2D.h"

Point2D::Point2D(){}


Point2D::Point2D(float xx, float yy)
{
	x = xx;
	y = yy;
}


Point2D::~Point2D()
{
}

void Point2D::setX(float xx){
	x = xx;
}

void Point2D::setY(float yy){
	y = yy;
}

float Point2D::getX(){
	return x;
}

float Point2D::getY(){
	return y;
}
