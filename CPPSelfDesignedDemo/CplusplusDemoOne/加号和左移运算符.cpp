#include <stdio.h>
#include<string>
#include <iostream>
using namespace std;

//运算符重载等于是在原来的运算符的功能上增加了一个功能
class Person
{
public:
	int m_A;
	int m_B;
	Person operator+(Person& p1)//局部运算符重载
	{
		Person temp;
		temp.m_A = this->m_A + p1.m_A;
		temp.m_B = this->m_B + p1.m_B;
		return temp;
	}

	Person operator+(int num)//局部运算符重载 运算符可以多次重载
	{
		Person temp;
		temp.m_A = this->m_A +num;
		temp.m_B = this->m_B + num;
		return temp;
	}
};

//Person operator+(Person &p1,Person &p2)//全局运算符重载
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

void test_OperatorPlus()
{
#pragma region Global Operator
	Person p1;
	p1.m_A = 1;
	p1.m_B = 2;
	Person p2;
	p2.m_A = 1;
	p2.m_B = 2;
	Person p3;
	p3 = p1 + p2;
	//p3 = p1 operator+ p2;

	Person p4;
	p4.m_A = p1.m_A + 10;
	p4.m_B = p1.m_B + 10;
	cout <<"p3.A:" << p3.m_A << endl;
	cout << "p3.B:" << p3.m_B << endl;
	cout << "p4.A:" << p4.m_A << endl;
	cout << "p4.B:" << p4.m_B << endl;
#pragma endregion
	
}

//只能运用全局函数重载左移运算符(成员函数变量无法实现Cout在左边的功能) ,链式编程思想
ostream& operator<<(ostream& out, Person& p)//返回引用，是为了返回对象本身，而不是新的对象 
{
	out << "m_A=" << p.m_A << " m_B=" << p.m_B;
	return out;
}
void test_OperatorZuoyi()
{
	Person p;
	p.m_A = 1;
	p.m_B = 2;
	cout << p <<" xixi" << endl;
}
void main_PlusA()
{
	test_OperatorPlus();
	test_OperatorZuoyi();
}