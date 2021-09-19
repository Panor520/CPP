#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class ClassTemplateTestPer
{
public:
	ClassTemplateTestPer(T1 name, T2 age);
	void showPerson();
	T1 Name;
	T2 Age;
};