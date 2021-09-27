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

	//菜单
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
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