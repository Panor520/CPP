#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Identity.h"
#include "orderFile.h"

class Teacher :public Identity
{
public:

	Teacher();

	//�вι���
	Teacher(int empId,string name,string pwd);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;
};