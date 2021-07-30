#include <iostream>
using namespace std;
//重新定义在基类中的虚函数这种操作被叫做动态链接或后期绑定，不使用虚函数，每次调用子类的同名方法时访问的总是基类的同名方法（静态链接）。
class Shape
{
public :
	int x;
protected:
	int width, length;
public:
	Shape(int a = 0,int b = 0)
	{
		width = a;
		length = b;
	}
	virtual int area()
	{
		cout << "Parent class area :"<<width* length << endl;
		return 0;
	}
	// pure virtual function
	//// 提供接口框架的纯虚函数
	virtual int area1() = 0;
};

class Rectangle :public Shape
{
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) {}
	int area()
	{
		cout << "Rectangle class area :"<< width * length << endl;
		return 0;
	}
	int area1()
	{
		return 0;
	}
};

int mainp()
{
	Shape *shape;//指针类不含参数
	Rectangle rec(10, 7);
	
	// 存储矩形的地址
	shape = &rec;//&取址符
	// 调用矩形的求面积函数 area
	shape->area();//指针类，用->访问符

	shape->x = 1;
	cout << "x=" << shape->x << endl;

	
	Rectangle r1(1,2);
	r1.area();
	return 0;
}