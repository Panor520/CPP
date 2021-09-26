//C++编译器至少给一个类添加3个函数：
//1.默认无参构造函数
//2.默认析构函数
//3.默认拷贝函数，对属性值进行拷贝
//-如果用户定义有有参构造函数，编译器就不在提供无参构造，但会提供拷贝构造
//--如果用户定义有拷贝构造函数，编译器就不再提供其它构造函数。
#include <iostream>
using namespace std;

/// <summary>
/// 完整有参构造 无参构造 拷贝构造函数声明类示例
/// </summary>
class Person
{
public:
	Person()
	{
		cout << "Default Constructor!" << endl;
	}
	Person(int a)
	{
		age = a;
	}
	Person(const Person& p)
	{
		age = p.age;
	}
	~Person()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};

///如下示例，未自定义默认无参构造函数，不能声明 Person1 p;
class Person1
{
public:
	Person1(int a)
	{
		age = a;
	}
	Person1(const Person1& p)
	{
		age = p.age;
	}
	~Person1()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};

/// <summary>
/// 如下示例：未自定义构造函数，定义有拷贝函数，故不能生命Person2 p;
/// </summary>
class Person2
{
public:
	Person2(const Person2& p)
	{
		age = p.age;
	}
	~Person2()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};
/// <summary>
/// 如下示例：定义有有参构造，未定义无参构造，未定义拷贝函数；但编译器会自动生成拷贝函数，不会生成无参构造
/// </summary>
class Person3
{
public:
	Person3(int a)
	{
		age = a;
	}
	~Person3()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};




void mainctt()
{

}