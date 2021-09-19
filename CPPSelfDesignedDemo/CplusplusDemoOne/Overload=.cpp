#include <string>
#include <iostream>
using namespace std;



class PersonEqual
{ 
public:
	PersonEqual(int age)
	{
		m_Age =new int(age);
	} 
	~PersonEqual()
	{
		if (m_Age!=NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	PersonEqual& operator=(PersonEqual &p)//PersonEqual �����ص��ǿ�����PersonEqual&������Ƕ�����
	{
		//��������ǳ����
		//ֻ�л����ĸ�ֵ����(����)
		//m_Age=p.m_Age;

		//����ʵ�����£�Ҫ�ȿ������Ƿ��ڶ�������������ͷŸɾ���Ȼ��������������ͷ�����
		if (m_Age!=NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//�������
		m_Age=new int(*p.m_Age);

		return *this;//this ����ö����ָ�룬*this���������
	}
	int *m_Age;
};

//���������=���أ��������ִ��ʱ���������Ϊ����PersonEqual����������ʱ����ִ������������������������m_Ageָ��Ķ���ͬһ���ڴ��ַ���ʵڶ�������ʱ�ͻ����
void ShowPerson()
{
	PersonEqual p(10);
	PersonEqual p1(11);
	PersonEqual p2(12);
	cout << *p.m_Age << endl;
	p1 = p;
	cout << *p1.m_Age << endl;

	cout << p.m_Age << endl;
	cout << p1.m_Age << endl;
	p = p1 = p2;

	cout << *p.m_Age << endl;

	cout << *p1.m_Age << endl;
	cout << *p2.m_Age << endl;
}

void main_Equal()
{
	ShowPerson();
}