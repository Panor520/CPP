#include <iostream>
using namespace std;

//��̬������ʼ�����ܱ�������Ķ����У�������������ⲿʹ��::��ʼ����
//�ڴ�����һ������ʱ�����еľ�̬���ݶ��ᱻ��ʼ��Ϊ��.
//��̬������ʼ�������ڲ���ʹ��һ�������⡣
class box
{
public:
	static int count;
	box(void)
	{
		cout << "count=" << count << endl;
	}

	static void getcount()
	{
		cout << "count=" << count+1 << endl;
	}
};
int box::count = 1;

//��̬��Աֻ��Ҫͨ�� ����::��̬��Ա�� �Ϳ��Է��ʣ����贴������
int mainsm()
{
	cout << "count=" << box::count << endl;
	box::getcount();
	box();//���캯��������ǰ������ľ�̬������ֵ���̾��ѱ����á�
	return 0;
}