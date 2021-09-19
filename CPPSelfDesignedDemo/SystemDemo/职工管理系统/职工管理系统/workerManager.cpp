#include "workerManager.h"

workerManager::workerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	} 
	//文件存在 但为空
	char ch;
	ifs >> ch;//文件末位的字符是eof,如果文件为空，就直接读到eof，故可由此判断出文件是否为空
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//存在，且不为空
	int num = this->get_EmpNum();
	//cout << "职工人数为："<<num << endl;
	this->m_EmpNum = num;

	this->m_EmpArry = new Worker * [this->m_EmpNum];
	//初始化记录人数
	this->init_Emp();
}

workerManager::~workerManager()
{
	if (this->m_EmpArry!=NULL)
	{
		delete[] this->m_EmpArry;
		this->m_EmpArry = NULL;
	}
}

void workerManager::show_Menu()
{
	cout << "****************************" << endl;
	cout << "***** 欢迎使用职工管理系统****" << endl;
	cout << "*******0.退出管理程序*******" << endl;
	cout << "*******1.增加职工信息*******" << endl;
	cout << "*******2.显示职工信息*******" << endl;
	cout << "*******3.删除职工信息*******" << endl;
	cout << "*******4.修改职工信息*******" << endl;
	cout << "*******5.查找职工信息*******" << endl;
	cout << "*******6.按照编号排序*******" << endl;
	cout << "*******7.清空所有文档*******" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void workerManager::Add_Emp()
{
	cout << "Pls enter Number:" << endl;

	int getNum =0 ;
	cin >> getNum;

	if (getNum>0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + getNum;//历史人数+新增加人数

		//开辟新空间
		Worker** newSpace= new Worker* [newSize];//N个 Worker 对象

		if (this->m_EmpArry!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}

		//add new worker
		for (int i = 0; i < getNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第"<<i+1<<"个新职工编号："<< endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worke = NULL;
			switch (dSelect)
			{
			case 1:
				worke = new Employee(id,name,1);
				break;
			case 2:
				worke = new Manager(id, name, 2);
				break;
			case 3:
				worke = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worke;
		}

		//释放原有空间
		delete [] this->m_EmpArry;
		//更新空间的指向
		this->m_EmpArry = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		cout << "成功添加了"<<getNum<<"名新职工！"<< endl;

		this->Save();
	}
	else
	{
		cout << "输入数据有误！" << endl;
	}

	system("pause");
	system("cls");
}


void workerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArry[i]->m_Id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_DeptId << endl;
	}

	ofs.close();
}
 
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}
	ifs.close();

	return num;
}

void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worke = NULL;
		switch (dId)
		{
		case 1:
			worke = new Employee(id, name, dId);
			break;
		case 2:
			worke = new Manager(id, name, dId);
			break;
		case 3:
			worke = new Boss(id, name, dId);
			break;
		default:
			break;
		}

		this->m_EmpArry[index] = worke;
		index++;

	}

	ifs.close();
}

void workerManager::show_Emp()
{
	if (!this->m_FileIsEmpty)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArry[i]->showInfo();
		}
	}
	else
	{
		cout<<"文件不存在或为空！" << endl;
	}

	system("pause");
	system("cls");
}