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
		case 1://1.����ԤԼ
			s->applyOrder();
			break;
		case 2://2.�鿴�ҵ�ԤԼ
			s->showMyOrder();
			break;
		case 3://3.�鿴����ԤԼ
			s->showAllOrder();
			break;
		case 4://ȡ��ԤԼ
			s->cancelOrder();
			break;
		case 0://ע����¼
			delete stu;
			cout << "ѧ��ע���ɹ���" << endl;
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
		case 1://1.�鿴����ԤԼ
			th->showAllOrder();
			break;
		case 2://2.���ԤԼ
			th->validOrder();
			break;
		case 0://ע����¼
			delete teach;
			cout << "��ʦע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//����Ա�˵�
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->openMenu();
		//������ָ��תΪ����ָ�룬�������෽��
		Manager* man = (Manager*)manager;

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����˺ţ�" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "�鿴�˺ţ�" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "�鿴������" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;
			cout << "����Աע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "�밴��ȷ��ѡ�����룡" << endl;
			break;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);//����ʱ�������ո�ͽ���

	//���ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ��
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������˺ţ�" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId==id && fName == name && fPwd == pwd)
			{
				cout << "-----------ѧ����֤�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Student(id,name,pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ��֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "-----------��ʦ��֤�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)
		{
			if ( fName == name && fPwd == pwd)
			{
				cout << "-----------����Ա��֤�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�����ʦ��ݵ��Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��֤��¼ʧ��" << endl;

	system("pause");
	system("cls");
	return;
}

void main()
{
	while (true)
	{
		cout << "--------------����ԤԼϵͳ-----------"<<endl;
		cout << "------------------------------------" << endl;
		cout << "|                                 |" << endl;
		cout << "|         1.ѧ������               |" << endl;
		cout << "|         2.��ʦ                   |" << endl;
		cout << "|         3.����Ա	                |" << endl;
		cout << "|         0.ѧ������                |" << endl;
		cout << "|			                        |" << endl;
		cout << "------------------------------------" << endl;

		int select;
		cout << "���������ѡ��" << endl;
		cin >> select;

		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}