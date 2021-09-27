#include <iostream>
using namespace std;
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"

void main()
{

#pragma region TestRegion
	/*Worker* worke = NULL;
	worke = new Employee(1,"Tom",1);
	worke->showInfo();
	delete worke;

	worke = new Manager(2,"cc",2 );
	worke->showInfo();
	delete worke;

	worke = new Boss(3, "dd", 3);
	worke->showInfo();
	delete worke;*/
#pragma endregion

	
	workerManager wm;
	int choice = 0;
	while (true)
	{
		wm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;//跳出switch
		case 1://1.增加职工信息
			wm.Add_Emp();
			break;
		case 2://2.显示职工信息
			wm.show_Emp();
			break;
		case 3://3.删除职工信息
			break;
		case 4://4.修改职工信息
			break;
		case 5://5.查找职工信息
			break;
		case 6://6.按照编号排序
			break;
		case 7://7.清空所有文档
			break;
		default:
			system("cls");
			break;
		}
	}
}
