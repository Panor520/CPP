#include "Circle.h"


void Circle::setCenter(Point p)
{
	m_Center = p;
}
void Circle::setR(int r)
{
	m_R = r;
}
int Circle::getR()
{
	return m_R;
}
Point Circle::getCenter()
{
	return m_Center;
}