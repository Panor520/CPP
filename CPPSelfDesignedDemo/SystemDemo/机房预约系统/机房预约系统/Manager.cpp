#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();//��ʼ����ȡѧ����ʦ�����ļ�

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom crTemp;
	while (ifs>>crTemp.m_ComId&& ifs>>crTemp.m_MaxNum)
	{
		this->vRoom.push_back(crTemp);
	}

	//cout << "��ǰ��������Ϊ"<<vRoom.size() << endl;
	ifs.close();
}

//�˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա"<<this->m_Name<<"��¼��" << endl;
	cout << "--------------------------" << endl;
	cout << "-------1.����˺�---------" << endl;
	cout << "-------2.�鿴�˺�---------" << endl;
	cout << "-------3.�鿴����---------" << endl;
	cout << "-------4.���ԤԼ---------" << endl;
	cout << "-------0.ע����¼---------" << endl;
	cout << "--------------------------" << endl;
	cout << "-------��ѡ����Ĳ�����" << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����˺����ͣ�" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select=0;
	cin >> select;
	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		break;
	default:
		cout << "��������������ѡ������룡" << endl;
		break;
	}

	ofs.open(fileName,ios::out|ios::app);//���û���ļ��򴴽��ļ���������ļ��������ļ�β׷��
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (this->checkRecord(id,select))
	{
		cout << "�ļ����Ѵ�����ͬ��ŵĳ�Ա������ظ���ӣ�" << endl;
	}
	else
	{
		ofs << id << " " << name << " " << pwd << endl;
		cout << "��ӳɹ���" << endl;

		this->initVector();
	}
	ofs.close();

	system("pause");
	system("cls");
}


void PrintStudent(Student &s)
{
	cout << "��ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void PrintTeacher(Teacher& s)
{
	cout << "��ţ�" << s.m_EmpId << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ���˺�" << endl;
	cout << "2.�鿴���н�ʦ�˺ţ�" << endl;

	int select = 0;
	cin >> select;
	if (select==1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(this->vStudent.begin(),this->vStudent.end(), PrintStudent);
	}
	else if (select==2)
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(this->vTeacher.begin(), this->vTeacher.end(), PrintTeacher);
	}
	cout << endl;
	system("pause");
	system("cls");
}

void PrintRoom(ComputerRoom &c)
{
	cout << "�����ţ�" << c.m_ComId << " ����������" << c.m_MaxNum << endl;
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for_each(this->vRoom.begin(),this->vRoom.end(), PrintRoom);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream of(ORDER_FILE,ios::trunc);
	of.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//����ʱ�������ո�ͽ���

	//���ļ�������
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ������ڣ�" << endl;
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

	//���ļ�������
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ������ڣ�" << endl;
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
	if (type==1)//1ѧ��
	{
		for (vector<Student>::iterator i = this->vStudent.begin(); i !=this->vStudent.end() ; i++)
		{
			if (i->m_Id==id)
			{
				return true;
			}
		}
	}
	else if (type == 2)//2��ʦ
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