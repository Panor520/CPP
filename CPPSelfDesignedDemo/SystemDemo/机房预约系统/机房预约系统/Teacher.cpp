#include "Teacher.h"

Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;


}

//菜单界面
void Teacher::openMenu()
{
	cout << "欢迎教师" << this->m_Name << "登录！" << endl;
	cout << "--------------------------" << endl;
	cout << "-------1.查看预约---------" << endl;
	cout << "-------2.审核预约---------" << endl;
	cout << "-------0.注销登录---------" << endl;
	cout << "--------------------------" << endl;
	cout << "-------请选择你的操作：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile oFile;
	if (oFile.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < oFile.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << " 预约日期： 周" << oFile.m_orderData[i]["date"];
		cout << " 时段：" << (oFile.m_orderData[i]["Interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << oFile.m_orderData[i]["stuId"];
		cout << " 姓名：" << oFile.m_orderData[i]["stuName"];
		cout << " 机房：" << oFile.m_orderData[i]["roomId"];

		string status = " 状态：";
		switch (atoi(oFile.m_orderData[i]["status"].c_str()))
		{
		case 1:
			status += "审核中";
			break;
		case 2:
			status += "预约成功";
			break;
		case -1:
			status = "审核未通过，预约失败";
			break;
		default:
			status += "预约已取消";
			break;
		}

		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder()
{
	OrderFile oFile;
	if (oFile.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	map<int, int> mTemp;
	cout << "待审核预约记录如下：" << endl;
	for (int i = 0; i < oFile.m_Size; i++)
	{
		if (oFile.m_orderData[i]["status"] == "1")
		{
			mTemp.insert(make_pair(index, i));//编号对应的文件中的下标
			cout << index++ << "、";
			cout << "预约日期： 周" << oFile.m_orderData[i]["date"];
			cout << " 时段：" << (oFile.m_orderData[i]["Interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << oFile.m_orderData[i]["roomId"];

			string status = " 状态：";
			switch (atoi(oFile.m_orderData[i]["status"].c_str()))
			{
			case 1:
				status += "审核中";
				break;
			case 2:
				status += "预约成功";
				break;
			case -1:
				status += "审核未通过，预约失败";
				break;
			default:
				status += "预约已取消";
				break;
			}

			cout << status << endl;
		}
	}

	cout << "请输入要审核通过的记录，0代表返回：" << endl;
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
				cout << "请输入审核结果：" << endl;
				cout << "----------1.通过" << endl;
				cout << "----------2.不通过" << endl;
				int s = 0;
				while (true)
				{
					cin >> s;
					if (s == 1 || s == 2)
					{
						s == 1 ? oFile.m_orderData[mTemp[select]]["status"] = "2" : oFile.m_orderData[mTemp[select]]["status"] = "-1";
						oFile.UpdateOrder();
						cout << "审核完毕！" << endl;
						system("pause");
						system("cls");
						break;
					}
					cout << "输入有误，请重新输入！" << endl;
				}
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
}