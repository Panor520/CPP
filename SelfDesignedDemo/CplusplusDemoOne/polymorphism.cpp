//��̬��Ϊ���ࣺ
//��̬��̬���������ء���������أ����ú�����
//��̬��̬����������麯������д��ʵ������ʱ��̬
//����
//��̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
//��̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ

#include <iostream>
using namespace std;
class polyAnimal
{
public:
	virtual void speak()
	{
		cout<<"Animal speak" << endl;
	}
};

class ployCat:public polyAnimal
{
public:
	void speak()//��д���������������б��������ȫһ�£�
	{
		cout << "cat speak" << endl;
	}
};

void ploySpeak(polyAnimal& p)
{
	p.speak();
}
void ploytest01()
{
	ployCat cat;
	ploySpeak(cat);//����ʱ������ִ�������е�speak,������д���������������б���ȫһ�£�
}

void main_ploybase()
{
	ploytest01();
}