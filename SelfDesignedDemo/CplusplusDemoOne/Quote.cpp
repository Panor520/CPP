#include <iostream>
using namespace std;
//����ʵ�ʾ���ָ�볣��
//int a=10;
//int &ref=a; �������Զ�����Ϊ int * const ref=&a;
//ref=20; �������Զ�����Ϊ�� *ref=20;
void QuoteGrammar()
{
	int a = 10;
	int c = 11;
	int& b = a;//���ñ���Ҫ��ʼ��,�ҳ�ʼ�����ܸ�������
	b = 20;
	b = c;//���Ǹ�ֵ�������������ø���
	cout << a << endl;
	cout << b << endl;
}

void ConstValue(const int &a)
{
	cout << a<<endl;
}

void QuoteSwap(int& a, int& b)//ʹ�����ý���������ָ�룬����ֱ���޸��βε�ֵ
{
	int temp = a;
	a = b;
	b = temp;
}

int& QuoteTest01()
{
	int a = 10;
	return a;
}

int& QuoteTest02()
{
	static int a = 20;
	return a;
}

void test01()
{
	int a = 10;
	int b = 20;
	QuoteSwap(a,b);
	cout << a << endl;
	cout << b << endl;
}

void test02()
{
	int& c = QuoteTest01();
	cout << c << endl;
	cout << c << endl;

	int& x = QuoteTest02();
	cout << x << endl;
	cout << x << endl;
	QuoteTest02() = 100;//�������õĺ������Ա���ֵ

	cout << x << endl;
}

void mainQu()
{
	//QuoteGrammar();
	//test01();
	test02();
}