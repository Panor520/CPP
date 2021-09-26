#include <string>
#include <iostream>
using namespace std;

#pragma region 类模板和函数模板区别


//类模板和函数模板区别：
//1.类模板没有自动类型推导的使用方式,都是显示调用
//2.类模板在模板参数列表中可以有默认参数
template <typename nameType =string,typename ageType = int>//指定默认类型的模板
class ClAFuncDiffTemplate
{
public:
	ClAFuncDiffTemplate(nameType name,ageType age)
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

void test01_clandfuncDiff()
{
	//ClAFuncDiffTemplate cd("Person",18);//error 无法自动推出模板类型
	ClAFuncDiffTemplate<> cd("Person", 18);//模板中指定了默认类型，这个地方的类型可以不传，即使用默认的
	cd.ShowPerson();
}

#pragma endregion

#pragma region 类模板中成员函数创建时机
//类模板中成员函数创建时机：
//类模板中成员函数在调用时才去创建，也就是确定了模板类型后再创建

#pragma endregion



void main_Clasandfuncdiff()
{
	test01_clandfuncDiff();
}