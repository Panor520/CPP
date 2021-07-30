#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	//构造函数
	Employee(int id,string name,int dId);//职工号 名字 部门ID

	virtual void showInfo();

	virtual string getDeptName();
};