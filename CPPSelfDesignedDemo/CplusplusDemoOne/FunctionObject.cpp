#include <string>
#include <iostream>
using namespace std;

//�º�����������д����������øò�����ʱ����ʹ�÷º���������ʹ�� �����������
//�º��������ԣ�
//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
//2.�º����ڵ���ʱ�������Լ���״̬
//3.�������������Ϊ��������

class Fo_MyAdd
{
public:
	int operator()(int a,int b)//��д���Ų�����
	{
		return a + b;
	}
};


//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test_fo01()
{
	Fo_MyAdd ma;//������������
	int x= ma(1,2);//�º�������һ����ͨ�������ʵ�ֵ�
	cout<<"�º������ý����" << x << endl;
}

//2.�º����ڵ���ʱ�������Լ���״̬
//������ͨ�����ĵ��ô�����Ҫȫ�ֱ�������¼�����º�������Ϳ��Լ�¼
class fo_print
{
	friend void fo_testo2();
public:
	fo_print()
	{
		this->count = 0;
	}
	void operator()(string x)
	{
		cout << x << endl;
		this->count++;
	}
private:
	int count;//ģ���ڲ��Լ���״̬
};

void fo_testo2()
{
	fo_print p;
	p("11111");
	p("22222");
	p("33333");
	p("44444");

	cout <<"�º������ô�����" << p.count << endl;
}

//3.�������������Ϊ��������
void doPrint_fo(fo_print &a)
{
	a("test ������");
}

void test03_fo()
{
	fo_print p;
	doPrint_fo(p);//����������Ϊ��������
}

void main_fo()
{
	//test_fo01();
	//fo_testo2();
	test03_fo();
}