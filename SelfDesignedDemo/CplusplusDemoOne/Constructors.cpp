//C++���������ٸ�һ�������3��������
//1.Ĭ���޲ι��캯��
//2.Ĭ����������
//3.Ĭ�Ͽ���������������ֵ���п���
//-����û��������вι��캯�����������Ͳ����ṩ�޲ι��죬�����ṩ��������
//--����û������п������캯�����������Ͳ����ṩ�������캯����
#include <iostream>
using namespace std;

/// <summary>
/// �����вι��� �޲ι��� �������캯��������ʾ��
/// </summary>
class Person
{
public:
	Person()
	{
		cout << "Default Constructor!" << endl;
	}
	Person(int a)
	{
		age = a;
	}
	Person(const Person& p)
	{
		age = p.age;
	}
	~Person()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};

///����ʾ����δ�Զ���Ĭ���޲ι��캯������������ Person1 p;
class Person1
{
public:
	Person1(int a)
	{
		age = a;
	}
	Person1(const Person1& p)
	{
		age = p.age;
	}
	~Person1()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};

/// <summary>
/// ����ʾ����δ�Զ��幹�캯���������п����������ʲ�������Person2 p;
/// </summary>
class Person2
{
public:
	Person2(const Person2& p)
	{
		age = p.age;
	}
	~Person2()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};
/// <summary>
/// ����ʾ�����������вι��죬δ�����޲ι��죬δ���忽�������������������Զ����ɿ������������������޲ι���
/// </summary>
class Person3
{
public:
	Person3(int a)
	{
		age = a;
	}
	~Person3()
	{
		cout << "Destructor!" << endl;
	}
private:
	int age;
};




void mainctt()
{

}