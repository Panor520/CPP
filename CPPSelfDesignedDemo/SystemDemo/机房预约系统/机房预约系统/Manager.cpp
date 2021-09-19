#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();//初始化读取学生教师数据文件

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom crTemp;
	while (ifs>>crTemp.m_ComId&& ifs>>crTemp.m_MaxNum)
	{
		this->vRoom.push_back(crTemp);
	}

	//cout << "当前机房数量为"<<vRoom.size() << endl;
	ifs.close();
}

//菜单
void Manager::openMenu()
{
	cout << "欢迎管理员"<<this->m_Name<<"登录！" << endl;
	cout << "--------------------------" << endl;
	cout << "-------1.添加账号---------" << endl;
	cout << "-------2.查看账号---------" << endl;
	cout << "-------3.查看机房---------" << endl;
	cout << "-------4.清空预约---------" << endl;
	cout << "-------0.注销登录---------" << endl;
	cout << "--------------------------" << endl;
	cout << "-------请选择你的操作：" << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "添加账号类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select=0;
	cin >> select;
	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		break;
	default:
		cout << "输入有误，请重新选择后输入！" << endl;
		break;
	}

	ofs.open(fileName,ios::out|ios::app);//如果没有文件则创建文件，如果有文件，则在文件尾追加
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (this->checkRecord(id,select))
	{
		cout << "文件中已存在相同编号的成员，请忽重复添加！" << endl;
	}
	else
	{
		ofs << id << " " << name << " " << pwd << endl;
		cout << "添加成功！" << endl;

		this->initVector();
	}
	ofs.close();

	system("pause");
	system("cls");
}


void PrintStudent(Student &s)
{
	cout << "编号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void PrintTeacher(Teacher& s)
{
	cout << "编号：" << s.m_EmpId << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生账号" << endl;
	cout << "2.查看所有教师账号：" << endl;

	int select = 0;
	cin >> select;
	if (select==1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(this->vStudent.begin(),this->vStudent.end(), PrintStudent);
	}
	else if (select==2)
	{
		cout << "所有教师信息如下：" << endl;
		for_each(this->vTeacher.begin(), this->vTeacher.end(), PrintTeacher);
	}
	cout << endl;
	system("pause");
	system("cls");
}

void PrintRoom(ComputerRoom &c)
{
	cout << "机房号：" << c.m_ComId << " 房间容量：" << c.m_MaxNum << endl;
}
//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for_each(this->vRoom.begin(),this->vRoom.end(), PrintRoom);
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream of(ORDER_FILE,ios::trunc);
	of.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//读的时候碰到空格就结束

	//若文件不存在
	if (!ifs.is_open())
	{
		cout << "学生文件不存在！" << endl;
		ifs.close();
		return;
	}

	vStudent.clear();
	Student sTem;
	while (ifs >> sTem.m_Id && ifs >> sTem.m_Name && ifs >> sTem.m_Pwd)
	{
		this->vStudent.push_back(sTem);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	//若文件不存在
	if (!ifs.is_open())
	{
		cout << "教师文件不存在！" << endl;
		ifs.close();
		return;
	}

	vTeacher.clear();
	Teacher tTem;
	while (ifs >> tTem.m_EmpId && ifs >> tTem.m_Name && ifs >> tTem.m_Pwd)
	{
		this->vTeacher.push_back(tTem);
	}
	ifs.close();
}

bool Manager::checkRecord(int id,int type)
{
	if (type==1)//1学生
	{
		for (vector<Student>::iterator i = this->vStudent.begin(); i !=this->vStudent.end() ; i++)
		{
			if (i->m_Id==id)
			{
				return true;
			}
		}
	}
	else if (type == 2)//2教师
	{
		for (vector<Teacher>::iterator i = this->vTeacher.begin(); i != this->vTeacher.end(); i++)
		{
			if (i->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}