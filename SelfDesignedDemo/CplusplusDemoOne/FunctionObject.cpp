#include <string>
#include <iostream>
using namespace std;

//�º�����������д������
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
	int x= ma(1,2);//�º������� ����
	cout<<"�º������ý����" << x << endl;
}

void main()
{
	test_fo01();
}