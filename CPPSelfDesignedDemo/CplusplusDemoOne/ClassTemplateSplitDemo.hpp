#pragma once
#include <iostream>
#include <string>
using namespace std;
//将类模板的声明和实现都写这里
template <class T1, class T2>
class ClassTemplateTestPer
{
public:
	ClassTemplateTestPer(T1 name, T2 age);
	void showPerson();
	T1 Name;
	T2 Age;
};


template <class T1, class T2>
ClassTemplateTestPer<T1, T2>::ClassTemplateTestPer(T1 name, T2 age)
{
	this->Name = name;
	this->Age = age;
}

template <class T1, class T2>
void ClassTemplateTestPer<T1, T2> ::showPerson()
{
	cout << this->Name << " " << this->Age << endl;
}
