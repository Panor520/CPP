#include <iostream>
using namespace std;

//��̬��Ա�ͷǾ�̬ͬ����Ա��������������
class SameNameBase
{
public:
	SameNameBase()
	{
		a = 100;
	}
	void fun()
	{
		cout << "father fun" << endl;
	}
	void fun(int a)
	{
		cout << "father fun(int a)" << endl;
	}
	int a;
};

class SameNameSon :public SameNameBase
{
public:
	SameNameSon()
	{
		a = 200;
	}
	void fun()
	{
		cout << "son fun" << endl;
	}
	int a;
};

void main_�̳�ͬ����Ա()
{
	SameNameSon s;
	cout << s.a << endl;//ֱ�ӵ��õ�������
	cout << s.SameNameBase::a << endl;//���û���Ҫ��������
	s.fun();
	s.SameNameBase::fun();
	//s.fun(1);//������ӵ���븸��ͬ���ĺ����������е�����ͬ���������������أ��������ص���ֻ��ͨ��������ķ�ʽ����
	s.SameNameBase::fun(1);
}