#include "Student.h"

Student::Student()
{

}

//�вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom crTemp;
	while (ifs >> crTemp.m_ComId && ifs >> crTemp.m_MaxNum)
	{
		this->vRoom.push_back(crTemp);
	}

	//cout << "��ǰ��������Ϊ"<<vRoom.size() << endl;
	ifs.close();
}

//�˵�����
void Student::openMenu()
{
	cout << "��ӭѧ��" << this->m_Name << "��¼��" << endl;
	cout << "--------------------------" << endl;
	cout << "-------1.����ԤԼ---------" << endl;
	cout << "-------2.�鿴�ҵ�ԤԼ---------" << endl;
	cout << "-------3.�鿴����ԤԼ---------" << endl;
	cout << "-------4.ȡ��ԤԼ---------" << endl;
	cout << "-------0.ע����¼---------" << endl;
	cout << "--------------------------" << endl;
	cout << "-------��ѡ����Ĳ�����" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "ѡ�����ڣ�" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << "���������ѡ��" << endl;

	int sOne = 0;
	int sTwo = 0;
	int sThree = 0;
	while (true)
	{
		cin >> sOne;
		if (sOne >= 1 && sOne <= 5)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}

	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true)
	{
		cin >> sTwo;
		if (sTwo >= 1 && sTwo <= 2)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << this->vRoom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << this->vRoom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << this->vRoom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> sThree;
		if (sTwo >= 1 && sTwo <= 3)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << sOne << " ";
	ofs << "Interval:" << sTwo << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << sThree << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	cout << "ԤԼ�ɹ�������У�" << endl;
	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
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
		//string ����.c_str()תchar const  *
		//���� atoi (char const  *) תint
		if (atoi(oFile.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
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
				status = "���δͨ����ԤԼʧ��";
				break;
			default:
				status += "ԤԼ��ȡ��";
				break;
			}

			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
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

//ȡ��ԤԼ
void Student::cancelOrder()
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
	for (int i = 0; i < oFile.m_Size; i++)
	{
		//string ����.c_str()תchar const  *
		//���� atoi (char const  *) תint
		if (atoi(oFile.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (oFile.m_orderData[i]["status"] == "1" || oFile.m_orderData[i]["status"] == "2")
			{
				mTemp.insert(make_pair(index,i));//��Ŷ�Ӧ���ļ��е��±�
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
					status = "���δͨ����ԤԼʧ��";
					break;
				default:
					status += "ԤԼ��ȡ��";
					break;
				}

				cout << status << endl;
			}
		}
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������Ҫȡ�������к�(0������)��" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select < oFile.m_Size)
		{
			if (select==0)
			{
				break;
			}
			else
			{
				oFile.m_orderData[mTemp[select]]["status"] = "0";
				oFile.UpdateOrder();
				cout << "��ȡ��ԤԼ��" << endl;

				system("pause");
				system("cls");
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}

	
}