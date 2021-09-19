#include <iostream>
using namespace std;

//1.函数声明和寒暑表实现只能有一个地方有默认值
//2.有默认值的参数右边的参数都必须有默认值 例：void Function(int a=10,int b){} 这种会报错
int FunctionOne(int a , int b );

int FunctionOne(int a , int b = 20)
{
	return a + b;
}
////////////////////////////////////////////////////////////////////占位参数
//占位参数:第二个参数就是占位参数,调用时必须传参
void FunctionThree(int a,int)
{

}
//占位参数也可以有默认值
void FunctionFour(int a, int = 10)
{

}

/// ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////函数重载
void OverLoadOne(double a, int b)
{
	cout << "OverLoadOne(double a, int b)" << endl;
}
void OverLoadOne(int a, double b)
{
	cout << "OverLoadTwo(int a, double b)" << endl;
}
//返回值不能当做重载条件
//int OverLoadOne(int a, double b)
//{
//	cout << "OverLoadTwo(int a, double b)" << endl;
//}

void func(int& a)//
{
	cout << "func(int& a)" << endl;
}
void func(const int& a)
{
	cout << "const func(int& a)" << endl;
}

void Overload()
{
	OverLoadOne(3.14,1);
	OverLoadOne( 1, 3.14);
	int a = 10;
	func(a);
	func(10);//int &a=10; 这种语法错误，会直接走const参数的 func
	const int b = 10;
	func(b);
}

void mainFu()
{
	//FunctionOne(100);
	Overload();
}