#include "Teacher.h"

Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;


}

//�˵�����
void Teacher::openMenu()
{
	cout << "��ӭ��ʦ" << this->m_Name << "��¼��" << endl;
	cout << "--------------------------" << endl;
	cout << "-------1.�鿴ԤԼ---------" << endl;
	cout << "-------2.���ԤԼ---------" << endl;
	cout << "-------0.ע����¼---------" << endl;
	cout << "--------------------------" << endl;
	cout << "-------��ѡ����Ĳ�����" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile oFile;
	if (oFile.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < oFile.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << " ԤԼ���ڣ� ��" << oFile.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (oFile.m_orderData[i]["Interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << oFile.m_orderData[i]["stuId"];
		cout << " ������" << oFile.m_orderData[i]["stuName"];
		cout << " ������" << oFile.m_orderData[i]["roomId"];

		string status = " ״̬��";
		switch (atoi(oFile.m_orderData[i]["status"].c_str()))
		{
		case 1:
			status += "�����";
			break;
		case 2:
			status += "ԤԼ�ɹ�";
			break;
		case -1:
			status = "���δͨ����ԤԼʧ��";
			break;
		default:
			status += "ԤԼ��ȡ��";
			break;
		}

		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile oFile;
	if (oFile.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	map<int, int> mTemp;
	cout << "�����ԤԼ��¼���£�" << endl;
	for (int i = 0; i < oFile.m_Size; i++)
	{
		if (oFile.m_orderData[i]["status"] == "1")
		{
			mTemp.insert(make_pair(index, i));//��Ŷ�Ӧ���ļ��е��±�
			cout << index++ << "��";
			cout << "ԤԼ���ڣ� ��" << oFile.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (oFile.m_orderData[i]["Interval"] == "1" ? "����" : "����");
			cout << " ������" << oFile.m_orderData[i]["roomId"];

			string status = " ״̬��";
			switch (atoi(oFile.m_orderData[i]["status"].c_str()))
			{
			case 1:
				status += "�����";
				break;
			case 2:
				status += "ԤԼ�ɹ�";
				break;
			case -1:
				status += "���δͨ����ԤԼʧ��";
				break;
			default:
				status += "ԤԼ��ȡ��";
				break;
			}

			cout << status << endl;
		}
	}

	cout << "������Ҫ���ͨ���ļ�¼��0�����أ�" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select < oFile.m_Size)
		{
			if (select == 0)
			{
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "----------1.ͨ��" << endl;
				cout << "----------2.��ͨ��" << endl;
				int s = 0;
				while (true)
				{
					cin >> s;
					if (s == 1 || s == 2)
					{
						s == 1 ? oFile.m_orderData[mTemp[select]]["status"] = "2" : oFile.m_orderData[mTemp[select]]["status"] = "-1";
						oFile.UpdateOrder();
						cout << "�����ϣ�" << endl;
						system("pause");
						system("cls");
						break;
					}
					cout << "�����������������룡" << endl;
				}
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
}