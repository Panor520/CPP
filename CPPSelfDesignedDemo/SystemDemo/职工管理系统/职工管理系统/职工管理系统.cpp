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
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;//����switch
		case 1://1.����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2://2.��ʾְ����Ϣ
			wm.show_Emp();
			break;
		case 3://3.ɾ��ְ����Ϣ
			break;
		case 4://4.�޸�ְ����Ϣ
			break;
		case 5://5.����ְ����Ϣ
			break;
		case 6://6.���ձ������
			break;
		case 7://7.��������ĵ�
			break;
		default:
			system("cls");
			break;
		}
	}
}
