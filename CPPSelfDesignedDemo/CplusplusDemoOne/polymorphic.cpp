#include <iostream>
using namespace std;
//���¶����ڻ����е��麯�����ֲ�����������̬���ӻ���ڰ󶨣���ʹ���麯����ÿ�ε��������ͬ������ʱ���ʵ����ǻ����ͬ����������̬���ӣ���
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
	//// �ṩ�ӿڿ�ܵĴ��麯��
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
	Shape *shape;//ָ���಻������
	Rectangle rec(10, 7);
	
	// �洢���εĵ�ַ
	shape = &rec;//&ȡַ��
	// ���þ��ε���������� area
	shape->area();//ָ���࣬��->���ʷ�

	shape->x = 1;
	cout << "x=" << shape->x << endl;

	
	Rectangle r1(1,2);
	r1.area();
	return 0;
}