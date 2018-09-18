#pragma once
class Point2D
{
public:
	Point2D();
	Point2D(float xx, float yy);
	~Point2D();

	float getX();
	float getY();
	void setX(float xx);
	void setY(float yy);

private:
	float x;
	float y;
};

