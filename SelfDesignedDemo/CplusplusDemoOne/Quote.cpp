#include <iostream>
using namespace std;
//引用实际就是指针常量
//int a=10;
//int &ref=a; 编译器自动编译为 int * const ref=&a;
//ref=20; 编译器自动编译为： *ref=20;
void QuoteGrammar()
{
	int a = 10;
	int c = 11;
	int& b = a;//引用必须要初始化,且初始化后不能更改引用
	b = 20;
	b = c;//这是赋值操作，不是引用更改
	cout << a << endl;
	cout << b << endl;
}

void ConstValue(const int &a)
{
	cout << a<<endl;
}

void QuoteSwap(int& a, int& b)//使用引用交换，类似指针，可以直接修改形参的值
{
	int temp = a;
	a = b;
	b = temp;
}

int& QuoteTest01()
{
	int a = 10;
	return a;
}

int& QuoteTest02()
{
	static int a = 20;
	return a;
}

void test01()
{
	int a = 10;
	int b = 20;
	QuoteSwap(a,b);
	cout << a << endl;
	cout << b << endl;
}

void test02()
{
	int& c = QuoteTest01();
	cout << c << endl;
	cout << c << endl;

	int& x = QuoteTest02();
	cout << x << endl;
	cout << x << endl;
	QuoteTest02() = 100;//返回引用的函数可以被赋值

	cout << x << endl;
}

void mainQu()
{
	//QuoteGrammar();
	//test01();
	test02();
}