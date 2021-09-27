#include "workerManager.h"

workerManager::workerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	} 
	//�ļ����� ��Ϊ��
	char ch;
	ifs >> ch;//�ļ�ĩλ���ַ���eof,����ļ�Ϊ�գ���ֱ�Ӷ���eof���ʿ��ɴ��жϳ��ļ��Ƿ�Ϊ��
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//���ڣ��Ҳ�Ϊ��
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��"<<num << endl;
	this->m_EmpNum = num;

	this->m_EmpArry = new Worker * [this->m_EmpNum];
	//��ʼ����¼����
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
	cout << "***** ��ӭʹ��ְ������ϵͳ****" << endl;
	cout << "*******0.�˳��������*******" << endl;
	cout << "*******1.����ְ����Ϣ*******" << endl;
	cout << "*******2.��ʾְ����Ϣ*******" << endl;
	cout << "*******3.ɾ��ְ����Ϣ*******" << endl;
	cout << "*******4.�޸�ְ����Ϣ*******" << endl;
	cout << "*******5.����ְ����Ϣ*******" << endl;
	cout << "*******6.���ձ������*******" << endl;
	cout << "*******7.��������ĵ�*******" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

void workerManager::Add_Emp()
{
	cout << "Pls enter Number:" << endl;

	int getNum =0 ;
	cin >> getNum;

	if (getNum>0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + getNum;//��ʷ����+����������

		//�����¿ռ�
		Worker** newSpace= new Worker* [newSize];//N�� Worker ����

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

			cout << "�������"<<i+1<<"����ְ����ţ�"<< endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

		//�ͷ�ԭ�пռ�
		delete [] this->m_EmpArry;
		//���¿ռ��ָ��
		this->m_EmpArry = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		cout << "�ɹ������"<<getNum<<"����ְ����"<< endl;

		this->Save();
	}
	else
	{
		cout << "������������" << endl;
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
		cout<<"�ļ������ڻ�Ϊ�գ�" << endl;
	}

	system("pause");
	system("cls");
}