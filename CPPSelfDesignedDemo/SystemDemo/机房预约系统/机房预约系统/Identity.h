#pragma once
#include <string>
#include <iostream>
using namespace std;

class Identity
{
public:

	virtual void openMenu() = 0;

	string m_Name;
	string m_Pwd;
};