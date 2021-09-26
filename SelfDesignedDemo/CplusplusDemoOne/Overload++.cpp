#include <stdio.h>
#include <iostream>
using namespace std;

//this是指向自身对象的指针，* this是自身对象。
//
//也就是说return* this返回的是当前对象的克隆或者本身（若返回类型为A， 则是克隆， 若返回类型为A& ， 则是本身 ）。
//
//return this返回当前对象的地址（指向当前对象的指针）

class MyNum
{
	friend ostream& operator<<(ostream& out, MyNum n);
public:
	MyNum()
	{
		m_Num = 0;
	}
	//前置递增返回引用
	//overload 前置++
	MyNum& operator++()//返回引用类型，就是返回对象本身 //不这样做就无法实现嵌套++的效果
	{
		m_Num++;
		return *this;
	}
	//overload 后置++   后置递增返回值
	//MyNum operator++(int) int是一个占位参数，用于区分前置和后置递增
	MyNum operator++(int)//返回引用类型，就是返回对象本身
	{
		//先记录结果
		MyNum temp=*this;
		//后递增
		m_Num++;
		//最后返回记录的结果
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream &out,MyNum n)
{
	out << n.m_Num;
	return out;
}
void testPP()
{
	MyNum m;
	cout << m << endl;//需要重载左移运算符
	cout << ++m << endl;
	cout << ++(++m) << endl;

	MyNum n;
	cout << n << endl;
	cout << n++ << endl;
	cout << n << endl;
}
void main_pp()
{
	testPP();
}