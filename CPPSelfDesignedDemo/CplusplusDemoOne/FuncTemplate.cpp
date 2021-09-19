#include <iostream>
using namespace std;

#pragma region ����ת������



//�Զ������Ƶ�����ʱ���ܽ�����ʽת��
//��ʾָ������ʱ���Խ�����ʽת��
template <typename T>
T AddFunc(T a,T b)
{
	return a + b;
}

void FuncTemplate_Tesot01()
{
	int a = 10;
	int b = 20;
	cout << AddFunc(a, b) << endl;

	char c = 'c';

	//cout << AddFunc(a, c) << endl;//�Զ������Ƶ�����ʱ���ܽ�����ʽת��

	cout << AddFunc<int>(a, c) << endl;//��ʾָ������ʱ���Խ�����ʽת��
	
}

#pragma endregion

#pragma region ��ͨ�����ͺ���ģ����ù���
//��ͨ�����ͺ���ģ����ù���
//1���������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//2������ͨ����ģ������б�ķ�ʽǿ�Ƶ��ú���ģ��
//3������ģ��Ҳ���Է�������
//4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
template <typename T>
void testPrint(T a,T b)
{
	cout << "templatefunc" << endl;
}

template <typename T>
void testPrint(T a, T b,T c)
{
	cout << "templateOverloadfunc" << endl;
}

void testPrint(int a, int b)
{
	cout << "commonfunc" << endl;
}

void FuncTemplate_Tesot02()
{
	//testPrint(1, 2);//������ͨ��������
	testPrint<>(1,2);//ָ����ģ������б�ǿ�Ƶ���ģ��
	testPrint<>(1,2,3);

	char a = 'a';
	char b = 'b';
	testPrint(a, b);//���ʱ�����������ѡ�����ģ��func�������ǽ�������ʽת��Ϊint�������ͨ����

}

#pragma endregion

#pragma region ģ������Լ���չ

template <typename T>
bool MyCompare(T &A,T &B)
{
	if (A==B)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class TemplatePer
{
public:
	TemplatePer(int a)
	{
		this->a = a;
	}
	int a;
};

//��ģ�庯������ĳ�������Ƚ�ʱ�����Ը����ض������ƶ����ȵ��õ�ģ��
template<> bool MyCompare(TemplatePer &p1, TemplatePer &p2)
{
	if (p1.a==p2.a)
	{
		return true;
	}
	return false;
}


void FuncTemplate_Tesot03()
{
	TemplatePer p1(1);
	TemplatePer p2(2);
	cout<< MyCompare(p1,p2)<<endl;

}
#pragma endregion


void main_FuncTemplate()
{
	//FuncTemplate_Tesot01();
	//FuncTemplate_Tesot02();
	FuncTemplate_Tesot03();
}