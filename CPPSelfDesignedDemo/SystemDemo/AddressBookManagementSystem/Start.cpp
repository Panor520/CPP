#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

void ShowMenu()
{
	cout << "*********************" << endl;
	cout << "****1�������ϵ��****" << endl;
	cout << "****2����ʾ��ϵ��****" << endl;
	cout << "****3��ɾ����ϵ��****" << endl;
	cout << "****4��������ϵ��****" << endl;
	cout << "****5���޸���ϵ��****" << endl;
	cout << "****6�������ϵ��****" << endl;
	cout << "****0���˳�ͨѶ¼****" << endl;
	cout << "*********************" << endl;
}

struct Person
{
	string name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];

	int m_Size;
};

void AddPerson(struct Addressbooks* ab)
{
	if (ab->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		ab->personArray[ab->m_Size].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1����" << endl;
		cout << "2��Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab->personArray[ab->m_Size].m_Sex = sex;
				break;
			}
			cout << "���벻��ȷ�����������룺" << endl;
		}


		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		ab->personArray[ab->m_Size].m_Age = age;

		cout << "�������ֻ��ţ�" << endl;
		string phone;
		cin >> phone;
		ab->personArray[ab->m_Size].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		ab->personArray[ab->m_Size].m_Addr = addr;

		ab->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void ShowPerson(Addressbooks* ab)
{
	if (ab->m_Size == 0)
	{
		cout << "��ǰΪ�գ�" << endl;
	}
	else {
		cout << "��Ϣ���£�" << endl;
		for (int i = 0; i < ab->m_Size; i++)
		{
			cout << "������" << ab->personArray[i].name <<
				" �Ա�" << (ab->personArray[i].m_Sex == 1 ? "��" : "Ů") <<
				" ���䣺" << ab->personArray[i].m_Age <<
				" �绰��" << ab->personArray[i].m_Phone <<
				" ��ַ��" << ab->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* ab,string name)
{
	for (int i = 0; i < ab->m_Size; i++)
	{
		if (ab->personArray[i].name==name)
		{
			return i;
		}
	}
	return -1;
}
void DeletePerson(Addressbooks* ab)
{
	cout << "������ɾ��������";
	string name;
	cin >> name;
	int ret = isExist(ab, name);
	if (ret != -1)
	{
		for (int i = ret; i < ab->m_Size; i++)
		{
			if (ab->personArray[i].name == name)
			{
				ab->personArray[i] = ab->personArray[i + 1];
			}
		}
		ab->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	
	system("pause");
	system("cls");
}

int FindPerson(Addressbooks* ab)
{
	cout << "���������������";
	string name;
	cin >> name;
	if (isExist(ab,name)!=-1)
	{
		for (int i = 0; i < ab->m_Size; i++)
		{
			if (ab->personArray[i].name == name)
			{
				cout << "��Ϣ���£�" << endl;
				cout << "������" << ab->personArray[i].name <<
					" �Ա�" << (ab->personArray[i].m_Sex == 1 ? "��" : "Ů") <<
					" ���䣺" << ab->personArray[i].m_Age <<
					" �绰��" << ab->personArray[i].m_Phone <<
					" ��ַ��" << ab->personArray[i].m_Addr << endl;
				cout << "���ҳɹ���" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	
	system("pause");
	system("cls");

	return 0;
}

void ModifyPerson(Addressbooks *ab)
{
	cout << "������Ҫ�޸ĵ�������";
	string name;
	cin >> name;
	int i = isExist(ab, name);
	if (i != -1)
	{

		cout << "������������" << endl;
		string name;
		cin >> name;
		ab->personArray[i].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1����" << endl;
		cout << "2��Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab->personArray[i].m_Sex = sex;
				break;
			}
			cout << "���벻��ȷ�����������룺" << endl;
		}


		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		ab->personArray[i].m_Age = age;

		cout << "�������ֻ��ţ�" << endl;
		string phone;
		cin >> phone;
		ab->personArray[i].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		ab->personArray[i].m_Addr = addr;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void ClearPerson(Addressbooks* ab)
{
	ab->m_Size = 0;//�߼����
	cout << "�����ϣ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks ab;
	ab.m_Size = 0;


	int num;
	while (true)
	{
		ShowMenu();
		cin >> num;

		switch (num)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");//������Ļ�������������
			return 0;//�˳�
			break;
		case 1:
			AddPerson(&ab);
			break;
		case 2:
			ShowPerson(&ab);
			break;
		case 3:
			DeletePerson(&ab);
			break;
		case 4:
			FindPerson(&ab);
			break;
		case 5:
			ModifyPerson(&ab);
			break;
		case 6:
			ClearPerson(&ab);
			break;
		}
	}

	return 0;
}