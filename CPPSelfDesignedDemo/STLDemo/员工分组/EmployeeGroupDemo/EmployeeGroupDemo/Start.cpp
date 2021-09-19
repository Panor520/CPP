#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define CEHUA 0
#define MEISU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;//
	int m_Salary;//нˮ
};

void CreateWorker(vector<Worker> &v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker W;
		W.m_Name = "Ա��";//W.m_Name = "Ա��"+nameseed[i];��������취�ӿ��ܻ�Ӳ���
		W.m_Name += nameseed[i];
		W.m_Salary = rand() % 10000 + 10000;//10000~199999
		v.push_back(W);
	}
}
void TestPrintVector(vector<Worker> &v)
{
	for (vector<Worker>::iterator i = v.begin(); i !=v.end(); i++)
	{
		cout<<"Name:"<<(*i).m_Name<<" Salary:" << (*i).m_Salary << endl;

	}
	cout << "-----" << endl;
}

void setGroup(multimap<int, Worker> &mm, vector<Worker> &v)
{
	for (vector<Worker>::iterator i = v.begin(); i !=v.end(); i++)
	{
		//����������ű��
		int deptId = rand() % 3;//0 1 2 
		//��Ա�����뵽������
		mm.insert(make_pair(deptId,*i));
	}
}

void showWorkerByGroup(multimap<int, Worker> &mm)
{
	//0 A B C 1D E 2 F G...
	cout << "�߻�����Ա����" << endl;
	multimap<int, Worker>::iterator pos = mm.find(CEHUA);//����ֱ���ҵ���һ������������Ԫ�����ڵ�λ��
	int count = mm.count(CEHUA);
	int index = 0;
	for ( ; pos !=mm.end()&& index<count; pos++, index++)
	{
		cout << "������" << (*pos).second.m_Name << " нˮ��" << (*pos).second.m_Salary << endl;
	}

	cout << "��������Ա����" << endl;
	pos = mm.find(MEISU);//����ֱ���ҵ���һ������������Ԫ�����ڵ�λ��
	count = mm.count(MEISU);
	index = 0;
	for (; pos != mm.end() && index < count; pos++, index++)
	{
		cout << "������" << (*pos).second.m_Name << " нˮ��" << (*pos).second.m_Salary << endl;
	}

	cout << "�з�����Ա����" << endl;
	pos = mm.find(YANFA);//����ֱ���ҵ���һ������������Ԫ�����ڵ�λ��
	count = mm.count(YANFA);
	index = 0;
	for (; pos != mm.end() && index < count; pos++, index++)
	{
		cout << "������" << (*pos).second.m_Name << " нˮ��" << (*pos).second.m_Salary << endl;
	}
}

void main()
{
	srand((unsigned int)time(NULL));//�����������
	//����Ա��
	vector<Worker> vWorker;
	CreateWorker(vWorker);

	//���Դ���Ա��
	//TestPrintVector(vWorker);

	//Ա������
	multimap<int, Worker> mmap;
	setGroup(mmap, vWorker);

	//������ʾ
	showWorkerByGroup(mmap);

	system("pause");
}