#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Circle
{
public:
	void setCenter(Point p);
	void setR(int r);
	int getR();
	Point getCenter();
private:
	Point m_Center;
	int m_R;
};