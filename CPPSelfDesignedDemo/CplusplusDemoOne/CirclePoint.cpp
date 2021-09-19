#include <iostream>
using namespace std;
#include "Point.h"
#include "Circle.h"

//class Point
//{
//public:
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	int getX()
//	{
//		return m_X;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};
//
//class Circle
//{
//public:
//	void setCenter(Point p)
//	{
//		m_Center = p;
//	}
//	void setR(int r)
//	{
//		m_R =r ;
//	}
//	int getR()
//	{
//		return m_R;
//	}
//	Point getCenter()
//	{
//		return m_Center;
//	}
//private:
//	Point m_Center;
//	int m_R;
//};

void judge(Circle c,Point p)
{
	int distanceCircle =c.getR()* c.getR();
	int distanceP = (p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());
	if (distanceCircle== distanceP)
	{
		cout << "点在圆上" << endl;
	}
	else if (distanceCircle > distanceP)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

void mainCp()
{
	Point center;
	center.setX(10);
	center.setY(0);
	Circle c;
	c.setCenter(center);
	c.setR(10);

	Point p;
	p.setX(10);
	p.setY(9);

	judge(c,p);
}