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
	//默认无参构造
	Student();

	//有参构造
	Student(int id,string name,string pwd);

	//菜单界面
	virtual void openMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;

	//
	vector<ComputerRoom> vRoom;
};