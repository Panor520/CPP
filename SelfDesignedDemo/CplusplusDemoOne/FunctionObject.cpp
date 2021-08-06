#include <string>
#include <iostream>
using namespace std;

//仿函数：类中重写操作符
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
	int x= ma(1,2);//仿函数调用 可以
	cout<<"仿函数调用结果：" << x << endl;
}

void main()
{
	test_fo01();
}