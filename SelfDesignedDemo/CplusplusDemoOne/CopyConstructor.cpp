//�������캯����ʱ��
//1.ʹ��һ���Ѵ����Ķ�������ʼ��һ���¶���
//2.ֵ���ݵķ�ʽ������������ֵ
//3.��ֵ��ʽ���ؾֲ�����
//ǳ���������
//1.ǳ�������򵥵ĸ�ֵ�����������������Զ��Ŀ�����������ǳ����
//2.������ڶ�����������ռ䣬���п�����������Ҫ�Լ�����
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯����" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "��ֵ���캯����" << endl;
	}
	Person(const Person &a)
	{
		age = a.age;
		cout << "�������캯����" << endl;
	}
	~Person()
	{
		cout << "��������" << endl;
	}
private:
	int age;
};

void test1()
{
	Person p(10);
	Person p1(p);
}


void DoWork(Person p)//ֵ���ݾͻ´��һ������������������βθ�ֵ
{
	cout << "test ֵ���ݵķ�ʽ������������ֵ" << endl;
}

void test2()
{
	Person p;//����Ĭ�Ϲ��캯��
	DoWork(p);//�����������캯������p��ֵ��DoWork�Ĳ���Person p
}

Person DoWork2()
{
	Person p;
	return p;//���ص�Ҳ���Ƕ��������ں�������ʱ�����٣������ǿ���������һ���¶���
}

void test3()
{
	Person p = DoWork2();//pֱ�ӻ��DoWork2()���صĶ�����һ�����������캯��
}

/// <summary>
/// ��ȿ���
/// </summary>
class Banana
{
public:
	Banana(int a,int b)
	{
		age = a;
		height = new int(b);
	}
	Banana(const Banana &a)
	{
		age = a.age;
		height =new int(*a.height);
	}
	~Banana()
	{
		if (height!=NULL)
		{
			delete height;
		}
	}
public:
	int age;
	int* height;
};

/// <summary>
/// ��������������ڶ������ٵģ�һ��Ҫ�Լ��ṩ���캯������ֹǳ��������������
/// </summary>
void test4()
{
	Banana a(10,23);
	Banana b(a);

	cout << a.age << "--" << *a.height << endl;
	cout << b.age << "--" <<* b.height << endl;
}

void maincct()
{
	//test1();
	//test2();
	//test3();
	test4();
}
