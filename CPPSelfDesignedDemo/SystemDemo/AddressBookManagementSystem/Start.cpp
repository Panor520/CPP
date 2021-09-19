#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

void ShowMenu()
{
	cout << "*********************" << endl;
	cout << "****1、添加联系人****" << endl;
	cout << "****2、显示联系人****" << endl;
	cout << "****3、删除联系人****" << endl;
	cout << "****4、查找联系人****" << endl;
	cout << "****5、修改联系人****" << endl;
	cout << "****6、清空联系人****" << endl;
	cout << "****0、退出通讯录****" << endl;
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
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		ab->personArray[ab->m_Size].name = name;

		int sex;
		cout << "请输入性别：" << endl;
		cout << "1、男" << endl;
		cout << "2、女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab->personArray[ab->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入不正确，请重新输入：" << endl;
		}


		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		ab->personArray[ab->m_Size].m_Age = age;

		cout << "请输入手机号：" << endl;
		string phone;
		cin >> phone;
		ab->personArray[ab->m_Size].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		ab->personArray[ab->m_Size].m_Addr = addr;

		ab->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void ShowPerson(Addressbooks* ab)
{
	if (ab->m_Size == 0)
	{
		cout << "当前为空！" << endl;
	}
	else {
		cout << "信息如下：" << endl;
		for (int i = 0; i < ab->m_Size; i++)
		{
			cout << "姓名：" << ab->personArray[i].name <<
				" 性别：" << (ab->personArray[i].m_Sex == 1 ? "男" : "女") <<
				" 年龄：" << ab->personArray[i].m_Age <<
				" 电话：" << ab->personArray[i].m_Phone <<
				" 地址：" << ab->personArray[i].m_Addr << endl;
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
	cout << "请输入删除姓名：";
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	
	system("pause");
	system("cls");
}

int FindPerson(Addressbooks* ab)
{
	cout << "请输入查找姓名：";
	string name;
	cin >> name;
	if (isExist(ab,name)!=-1)
	{
		for (int i = 0; i < ab->m_Size; i++)
		{
			if (ab->personArray[i].name == name)
			{
				cout << "信息如下：" << endl;
				cout << "姓名：" << ab->personArray[i].name <<
					" 性别：" << (ab->personArray[i].m_Sex == 1 ? "男" : "女") <<
					" 年龄：" << ab->personArray[i].m_Age <<
					" 电话：" << ab->personArray[i].m_Phone <<
					" 地址：" << ab->personArray[i].m_Addr << endl;
				cout << "查找成功！" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	
	system("pause");
	system("cls");

	return 0;
}

void ModifyPerson(Addressbooks *ab)
{
	cout << "请输入要修改的姓名：";
	string name;
	cin >> name;
	int i = isExist(ab, name);
	if (i != -1)
	{

		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		ab->personArray[i].name = name;

		int sex;
		cout << "请输入性别：" << endl;
		cout << "1、男" << endl;
		cout << "2、女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab->personArray[i].m_Sex = sex;
				break;
			}
			cout << "输入不正确，请重新输入：" << endl;
		}


		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		ab->personArray[i].m_Age = age;

		cout << "请输入手机号：" << endl;
		string phone;
		cin >> phone;
		ab->personArray[i].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		ab->personArray[i].m_Addr = addr;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void ClearPerson(Addressbooks* ab)
{
	ab->m_Size = 0;//逻辑清空
	cout << "清空完毕！" << endl;
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
			cout << "欢迎下次使用" << endl;
			system("pause");//冻结屏幕，按任意键继续
			return 0;//退出
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