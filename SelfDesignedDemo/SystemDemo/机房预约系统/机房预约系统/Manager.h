#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "computerRoom.h"

class Manager:public Identity
{
public:
	//
	Manager();

	Manager(string name,string pwd);

	//�˵�
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//
	void initVector();

	//
	bool checkRecord(int id,int type);

	//
	vector<Student> vStudent;

	//
	vector<Teacher> vTeacher;

	//
	vector<ComputerRoom> vRoom;
};