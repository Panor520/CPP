#include <string>
#include <iostream>
using namespace std;



class PersonEqual
{ 
public:
	PersonEqual(int age)
	{
		m_Age =new int(age);
	} 
	~PersonEqual()
	{
		if (m_Age!=NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	PersonEqual& operator=(PersonEqual &p)//PersonEqual 代表返回的是拷贝，PersonEqual&代表的是对象本身
	{
		//编译器是浅拷贝
		//只有基本的赋值操作(如下)
		//m_Age=p.m_Age;

		//重载实现如下，要先看属性是否在堆区，如果有先释放干净，然后再深拷贝，避免释放问题
		if (m_Age!=NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//深拷贝操作
		m_Age=new int(*p.m_Age);

		return *this;//this 代表该对象的指针，*this代表对象本身
	}
	int *m_Age;
};

//如果不进行=重载，下面代码执行时会崩溃。因为两个PersonEqual对象在销毁时都会执行析构函数，但两个对象中m_Age指向的都是同一块内存地址，故第二次销毁时就会崩溃
void ShowPerson()
{
	PersonEqual p(10);
	PersonEqual p1(11);
	PersonEqual p2(12);
	cout << *p.m_Age << endl;
	p1 = p;
	cout << *p1.m_Age << endl;

	cout << p.m_Age << endl;
	cout << p1.m_Age << endl;
	p = p1 = p2;

	cout << *p.m_Age << endl;

	cout << *p1.m_Age << endl;
	cout << *p2.m_Age << endl;
}

void main_Equal()
{
	ShowPerson();
}