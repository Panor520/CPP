#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class OverPerson
{
public:
	OverPerson(int age,string name)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	bool operator==(OverPerson &p)
	{
		if (p.m_Age==this->m_Age && p.m_Name==this->m_Name)
		{
			return true;
		}
		return false;
	}
	bool operator!=(OverPerson& p)
	{
		if (p.m_Age == this->m_Age && p.m_Name == this->m_Name)
		{
			return false;
		}
		return true;
	}
	int m_Age;
	string m_Name;
};

void showOverperson()
{
	OverPerson p(18, "1");
	OverPerson p1(18, "1");

	if (p==p1)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "UnEqual" << endl;
	}

	if (p != p1)
	{
		cout << "UnEqual" << endl;
	}
	else
	{
		cout << "Equal" << endl;
	}
}

void main_ShowOverperson()
{
	showOverperson();
}