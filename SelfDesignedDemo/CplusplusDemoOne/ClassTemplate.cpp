#include <iostream>
#include <string>
using namespace std;

#pragma region EasyDemo
template <typename nameType,typename ageType>
class templateClassPer
{
public:
	templateClassPer(nameType name,ageType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void ShowPerson()
	{
		cout << this->m_Name << " " << this->m_Age << endl;
	}

	nameType m_Name;
	ageType m_Age;
};


void test01_ClassTemplate()
{
	templateClassPer<string,int> tcp("haha",18);
	tcp.ShowPerson();
}
#pragma endregion


#pragma region MyRegion
//类模板对象做函数参数
//1、指定传入类型
//2、参数模板化
//3、整个类模板化

template <typename T1,typename T2>
class	ClassPerson
{
public:
	ClassPerson(T1 a,T2 b)
	{
		this->m_Name = a;
		this->m_Age = b;
	}
	void showperson()
	{
		cout << this->m_Name << " " << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

//1、指定传入类型  这个最常用
void printP1(ClassPerson<string, int> &p)
{
	p.showperson();
}
void test02_ClassTemplate()
{
	ClassPerson<string, int> cl1("hah",18);
	printP1(cl1);
}

//2、参数模板化
template <typename T1, typename T2>
void printP2(ClassPerson<T1, T2>& p)
{
	p.showperson();
	//看模板类型的方法如下：
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
}
void test03_ClassTemplate()
{
	ClassPerson<string, int> cl1("xxxx", 19);
	printP2(cl1);
}
//3、整个类模板化
template <class T>
void printP3(T &p)
{
	p.showperson();
	//看模板类型的方法如下：
	cout << typeid(T).name() << endl;
}
void test04_ClassTemplate()
{
	ClassPerson<string, int> cl1("test04", 199);
	printP3(cl1);
}
#pragma endregion


void main_ClassTemplate()
//void main()
{
	//test01_ClassTemplate();
	//test02_ClassTemplate();
	//test03_ClassTemplate();
	test04_ClassTemplate();
}