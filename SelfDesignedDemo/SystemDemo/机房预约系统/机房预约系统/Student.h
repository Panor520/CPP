#pragma once
#include "Identity.h"
#include <string>
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "computerRoom.h"
#include "orderFile.h"
#include <iostream>
#include <map>

class Student:public Identity
{
public:
	//Ĭ���޲ι���
	Student();

	//�вι���
	Student(int id,string name,string pwd);

	//�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//
	vector<ComputerRoom> vRoom;
};