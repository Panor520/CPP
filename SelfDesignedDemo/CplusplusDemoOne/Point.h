#pragma once
#include <iostream>
using namespace std;
//ͷ�ļ�������������
class Point
{
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
private:
	int m_X;
	int m_Y;
};