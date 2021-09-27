#pragma once
#include <iostream>
using namespace std;
//头文件包含声明即可
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