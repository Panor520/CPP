#include <iostream>
using namespace std;

//1.���������ͺ����ʵ��ֻ����һ���ط���Ĭ��ֵ
//2.��Ĭ��ֵ�Ĳ����ұߵĲ�����������Ĭ��ֵ ����void Function(int a=10,int b){} ���ֻᱨ��
int FunctionOne(int a , int b );

int FunctionOne(int a , int b = 20)
{
	return a + b;
}
////////////////////////////////////////////////////////////////////ռλ����
//ռλ����:�ڶ�����������ռλ����,����ʱ���봫��
void FunctionThree(int a,int)
{

}
//ռλ����Ҳ������Ĭ��ֵ
void FunctionFour(int a, int = 10)
{

}

/// ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////��������
void OverLoadOne(double a, int b)
{
	cout << "OverLoadOne(double a, int b)" << endl;
}
void OverLoadOne(int a, double b)
{
	cout << "OverLoadTwo(int a, double b)" << endl;
}
//����ֵ���ܵ�����������
//int OverLoadOne(int a, double b)
//{
//	cout << "OverLoadTwo(int a, double b)" << endl;
//}

void func(int& a)//
{
	cout << "func(int& a)" << endl;
}
void func(const int& a)
{
	cout << "const func(int& a)" << endl;
}

void Overload()
{
	OverLoadOne(3.14,1);
	OverLoadOne( 1, 3.14);
	int a = 10;
	func(a);
	func(10);//int &a=10; �����﷨���󣬻�ֱ����const������ func
	const int b = 10;
	func(b);
}

void mainFu()
{
	//FunctionOne(100);
	Overload();
}