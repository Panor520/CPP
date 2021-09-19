#include "Student.h"

Student::Student()
{

}

//有参构造
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

	//cout << "当前机房数量为"<<vRoom.size() << endl;
	ifs.close();
}

//菜单界面
void Student::openMenu()
{
	cout << "欢迎学生" << this->m_Name << "登录！" << endl;
	cout << "--------------------------" << endl;
	cout << "-------1.申请预约---------" << endl;
	cout << "-------2.查看我的预约---------" << endl;
	cout << "-------3.查看所有预约---------" << endl;
	cout << "-------4.取消预约---------" << endl;
	cout << "-------0.注销登录---------" << endl;
	cout << "--------------------------" << endl;
	cout << "-------请选择你的操作：" << endl;
}

//申请预约
void Student::applyOrder()
{
	cout << "选择日期：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	cout << "请输入你的选择：" << endl;

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
		cout << "输入有误，请重新输入：" << endl;
	}

	cout << "请输入申请预约时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	while (true)
	{
		cin >> sTwo;
		if (sTwo >= 1 && sTwo <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << this->vRoom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << this->vRoom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << this->vRoom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> sThree;
		if (sTwo >= 1 && sTwo <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << sOne << " ";
	ofs << "Interval:" << sTwo << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << sThree << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	cout << "预约成功，审核中！" << endl;
	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder()
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
		//string 利用.c_str()转char const  *
		//利用 atoi (char const  *) 转int
		if (atoi(oFile.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
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
				status = "审核未通过，预约失败";
				break;
			default:
				status += "预约已取消";
				break;
			}

			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
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

//取消预约
void Student::cancelOrder()
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
	for (int i = 0; i < oFile.m_Size; i++)
	{
		//string 利用.c_str()转char const  *
		//利用 atoi (char const  *) 转int
		if (atoi(oFile.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (oFile.m_orderData[i]["status"] == "1" || oFile.m_orderData[i]["status"] == "2")
			{
				mTemp.insert(make_pair(index,i));//编号对应的文件中的下标
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
					status = "审核未通过，预约失败";
					break;
				default:
					status += "预约已取消";
					break;
				}

				cout << status << endl;
			}
		}
	}

	cout << "审核中或预约成功的记录可以取消，请输入要取消的序列号(0代表返回)：" << endl;
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
				cout << "已取消预约！" << endl;

				system("pause");
				system("cls");
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	
}