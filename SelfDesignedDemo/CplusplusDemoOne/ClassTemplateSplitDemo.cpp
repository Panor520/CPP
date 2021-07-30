#include "ClassTemplateSplitDemo.h"

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