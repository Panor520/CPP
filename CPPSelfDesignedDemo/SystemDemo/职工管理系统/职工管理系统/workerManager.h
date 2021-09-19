#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"

#define FILENAME "empFile.txt"

class workerManager
{
public:
	workerManager();

	void show_Menu();

	void exitSystem();

	void Add_Emp();

	void Save();

	int get_EmpNum();

	void init_Emp();

	void show_Emp();

	~workerManager();

	bool m_FileIsEmpty;

	int m_EmpNum;

	Worker** m_EmpArry;

};