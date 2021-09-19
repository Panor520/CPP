#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

void studentMenu(Identity*& stu)
{
	while (true)
	{
		stu->openMenu();

		Student* s = (Student*)stu;

		int select=0;
		cin >> select;
		switch (select)
		{
		case 1://1.申请预约
			s->applyOrder();
			break;
		case 2://2.查看我的预约
			s->showMyOrder();
			break;
		case 3://3.查看所有预约
			s->showAllOrder();
			break;
		case 4://取消预约
			s->cancelOrder();
			break;
		case 0://注销登录
			delete stu;
			cout << "学生注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

void TeacherMenu(Identity*& teach)
{
	while (true)
	{
		teach->openMenu();

		Teacher* th = (Teacher*)teach;

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://1.查看所有预约
			th->showAllOrder();
			break;
		case 2://2.审核预约
			th->validOrder();
			break;
		case 0://注销登录
			delete teach;
			cout << "教师注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//管理员菜单
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//管理员菜单
		manager->openMenu();
		//将父类指针转为子类指针，调用子类方法
		Manager* man = (Manager*)manager;

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			cout << "添加账号！" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "查看账号！" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "查看机房！" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;
			cout << "管理员注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "请按正确的选项输入！" << endl;
			break;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);//读的时候碰到空格就结束

	//若文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//教师
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入账号：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId==id && fName == name && fPwd == pwd)
			{
				cout << "-----------学生验证成功！" << endl;
				system("pause");
				system("cls");

				person = new Student(id,name,pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//教师验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "-----------教师验证成功！" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)
		{
			if ( fName == name && fPwd == pwd)
			{
				cout << "-----------管理员验证成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//进入教师身份的子菜单
				managerMenu(person);

				return;
			}
		}
	}

	cout << "验证登录失败" << endl;

	system("pause");
	system("cls");
	return;
}

void main()
{
	while (true)
	{
		cout << "--------------机房预约系统-----------"<<endl;
		cout << "------------------------------------" << endl;
		cout << "|                                 |" << endl;
		cout << "|         1.学生代表               |" << endl;
		cout << "|         2.老师                   |" << endl;
		cout << "|         3.管理员	                |" << endl;
		cout << "|         0.学生代表                |" << endl;
		cout << "|			                        |" << endl;
		cout << "------------------------------------" << endl;

		int select;
		cout << "请输入你的选择：" << endl;
		cin >> select;

		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://教师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}