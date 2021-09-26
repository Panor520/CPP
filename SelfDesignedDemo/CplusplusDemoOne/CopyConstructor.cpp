//拷贝构造函数的时机
//1.使用一个已创建的对象来初始化一个新对象
//2.值传递的方式给函数参数传值
//3.以值方式返回局部对象
//浅拷贝和深拷贝
//1.浅拷贝：简单的赋值拷贝操作，编译器自动的拷贝函数就是浅拷贝
//2.深拷贝：在堆区重新申请空间，进行拷贝操作，需要自己定义
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默认构造函数！" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "赋值构造函数！" << endl;
	}
	Person(const Person &a)
	{
		age = a.age;
		cout << "拷贝构造函数！" << endl;
	}
	~Person()
	{
		cout << "析构函数" << endl;
	}
private:
	int age;
};

void test1()
{
	Person p(10);
	Person p1(p);
}


void DoWork(Person p)//值传递就会拷贝一个副本出来，给这个形参赋值
{
	cout << "test 值传递的方式给函数参数传值" << endl;
}

void test2()
{
	Person p;//触发默认构造函数
	DoWork(p);//触发拷贝构造函数，将p赋值给DoWork的参数Person p
}

Person DoWork2()
{
	Person p;
	return p;//返回的也不是对象本身（会在函数结束时被销毁），而是拷贝出来的一个新对象
}

void test3()
{
	Person p = DoWork2();//p直接获得DoWork2()返回的对象；这一步不触发构造函数
}

/// <summary>
/// 深度拷贝
/// </summary>
class Banana
{
public:
	Banana(int a,int b)
	{
		age = a;
		height = new int(b);
	}
	Banana(const Banana &a)
	{
		age = a.age;
		height =new int(*a.height);
	}
	~Banana()
	{
		if (height!=NULL)
		{
			delete height;
		}
	}
public:
	int age;
	int* height;
};

/// <summary>
/// 如果类中属性有在堆区开辟的，一定要自己提供构造函数，防止浅拷贝带来的问题
/// </summary>
void test4()
{
	Banana a(10,23);
	Banana b(a);

	cout << a.age << "--" << *a.height << endl;
	cout << b.age << "--" <<* b.height << endl;
}

void maincct()
{
	//test1();
	//test2();
	//test3();
	test4();
}
