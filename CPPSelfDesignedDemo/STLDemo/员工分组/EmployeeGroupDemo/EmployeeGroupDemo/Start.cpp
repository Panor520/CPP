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
	int m_Salary;//薪水
};

void CreateWorker(vector<Worker> &v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker W;
		W.m_Name = "员工";//W.m_Name = "员工"+nameseed[i];采用这个办法加可能会加不上
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
		//产生随机部门编号
		int deptId = rand() % 3;//0 1 2 
		//将员工插入到分组中
		mm.insert(make_pair(deptId,*i));
	}
}

void showWorkerByGroup(multimap<int, Worker> &mm)
{
	//0 A B C 1D E 2 F G...
	cout << "策划部门员工：" << endl;
	multimap<int, Worker>::iterator pos = mm.find(CEHUA);//可以直接找到第一个符合条件的元素所在的位置
	int count = mm.count(CEHUA);
	int index = 0;
	for ( ; pos !=mm.end()&& index<count; pos++, index++)
	{
		cout << "姓名：" << (*pos).second.m_Name << " 薪水：" << (*pos).second.m_Salary << endl;
	}

	cout << "美术部门员工：" << endl;
	pos = mm.find(MEISU);//可以直接找到第一个符合条件的元素所在的位置
	count = mm.count(MEISU);
	index = 0;
	for (; pos != mm.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << (*pos).second.m_Name << " 薪水：" << (*pos).second.m_Salary << endl;
	}

	cout << "研发部门员工：" << endl;
	pos = mm.find(YANFA);//可以直接找到第一个符合条件的元素所在的位置
	count = mm.count(YANFA);
	index = 0;
	for (; pos != mm.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << (*pos).second.m_Name << " 薪水：" << (*pos).second.m_Salary << endl;
	}
}

void main()
{
	srand((unsigned int)time(NULL));//生成随机种子
	//创建员工
	vector<Worker> vWorker;
	CreateWorker(vWorker);

	//测试创建员工
	//TestPrintVector(vWorker);

	//员工分组
	multimap<int, Worker> mmap;
	setGroup(mmap, vWorker);

	//分组显示
	showWorkerByGroup(mmap);

	system("pause");
}