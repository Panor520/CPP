#include <iostream>
using namespace std;

#pragma region 类型转换事项



//自动类型推到调用时不能进行隐式转换
//显示指定类型时可以进行隐式转换
template <typename T>
T AddFunc(T a,T b)
{
	return a + b;
}

void FuncTemplate_Tesot01()
{
	int a = 10;
	int b = 20;
	cout << AddFunc(a, b) << endl;

	char c = 'c';

	//cout << AddFunc(a, c) << endl;//自动类型推到调用时不能进行隐式转换

	cout << AddFunc<int>(a, c) << endl;//显示指定类型时可以进行隐式转换
	
}

#pragma endregion

#pragma region 普通函数和函数模板调用规则
//普通函数和函数模板调用规则：
//1、如果函数模板和普通函数都可以调用，优先调用普通函数
//2、可以通过空模板参数列表的方式强制调用函数模板
//3、函数模板也可以发生重载
//4、如果函数模板可以产生更好的匹配，优先调用函数模板
template <typename T>
void testPrint(T a,T b)
{
	cout << "templatefunc" << endl;
}

template <typename T>
void testPrint(T a, T b,T c)
{
	cout << "templateOverloadfunc" << endl;
}

void testPrint(int a, int b)
{
	cout << "commonfunc" << endl;
}

void FuncTemplate_Tesot02()
{
	//testPrint(1, 2);//优先普通函数调用
	testPrint<>(1,2);//指定空模板参数列表强制调用模板
	testPrint<>(1,2,3);

	char a = 'a';
	char b = 'b';
	testPrint(a, b);//这个时候编译器优先选择调用模板func，而不是将参数隐式转换为int后调用普通函数

}

#pragma endregion

#pragma region 模板局限性及扩展

template <typename T>
bool MyCompare(T &A,T &B)
{
	if (A==B)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class TemplatePer
{
public:
	TemplatePer(int a)
	{
		this->a = a;
	}
	int a;
};

//当模板函数利用某个类做比较时，可以根据特定类型制定优先调用的模块
template<> bool MyCompare(TemplatePer &p1, TemplatePer &p2)
{
	if (p1.a==p2.a)
	{
		return true;
	}
	return false;
}


void FuncTemplate_Tesot03()
{
	TemplatePer p1(1);
	TemplatePer p2(2);
	cout<< MyCompare(p1,p2)<<endl;

}
#pragma endregion


void main_FuncTemplate()
{
	//FuncTemplate_Tesot01();
	//FuncTemplate_Tesot02();
	FuncTemplate_Tesot03();
}