#include <string>
#include <iostream>
using namespace std;

//仿函数：类中重写操作符后调用该操作符时就是使用仿函数，必须使用 函数对象调用
//仿函数的特性：
//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//2.仿函数在调用时可以有自己的状态
//3.函数对象可以作为参数传递

class Fo_MyAdd
{
public:
	int operator()(int a,int b)//重写括号操作符
	{
		return a + b;
	}
};


//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test_fo01()
{
	Fo_MyAdd ma;//创建函数对象
	int x= ma(1,2);//仿函数调用一定是通过类对象实现的
	cout<<"仿函数调用结果：" << x << endl;
}

//2.仿函数在调用时可以有自己的状态
//例：普通函数的调用次数需要全局变量来记录，但仿函数自身就可以记录
class fo_print
{
	friend void fo_testo2();
public:
	fo_print()
	{
		this->count = 0;
	}
	void operator()(string x)
	{
		cout << x << endl;
		this->count++;
	}
private:
	int count;//模拟内部自己的状态
};

void fo_testo2()
{
	fo_print p;
	p("11111");
	p("22222");
	p("33333");
	p("44444");

	cout <<"仿函数调用次数：" << p.count << endl;
}

//3.函数对象可以作为参数传递
void doPrint_fo(fo_print &a)
{
	a("test 参数！");
}

void test03_fo()
{
	fo_print p;
	doPrint_fo(p);//函数对象作为参数传递
}

void main_fo()
{
	//test_fo01();
	//fo_testo2();
	test03_fo();
}