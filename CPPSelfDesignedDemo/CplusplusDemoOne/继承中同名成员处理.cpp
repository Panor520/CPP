#include <iostream>
using namespace std;

//静态成员和非静态同名成员都采用下述方法
class SameNameBase
{
public:
	SameNameBase()
	{
		a = 100;
	}
	void fun()
	{
		cout << "father fun" << endl;
	}
	void fun(int a)
	{
		cout << "father fun(int a)" << endl;
	}
	int a;
};

class SameNameSon :public SameNameBase
{
public:
	SameNameSon()
	{
		a = 200;
	}
	void fun()
	{
		cout << "son fun" << endl;
	}
	int a;
};

void main_继承同名成员()
{
	SameNameSon s;
	cout << s.a << endl;//直接调用的是子类
	cout << s.SameNameBase::a << endl;//调用基类要加作用域
	s.fun();
	s.SameNameBase::fun();
	//s.fun(1);//当子类拥有与父类同名的函数，父类中的所有同名函数（包括重载）都被隐藏掉，只能通过作用域的方式调用
	s.SameNameBase::fun(1);
}