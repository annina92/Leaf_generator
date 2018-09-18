
#pragma once

class Point3D
{
public:
	Point3D();
	Point3D(float a, float b, float c);

	float getX(){ return x; };
	float getY(){ return y; };
	float getZ(){ return z; };

	//void drawPoint();

	~Point3D();

private:
	float x, y, z;
};

