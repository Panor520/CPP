#include <iostream>
#include <string>
using namespace std;

//�д���������������Ҳ�ǳ����࣬�޷�ʵ��������
//ֻ���ڻ����ж����������������������е����������Żᱻ����
class chunxugou_Animal
{
public:
	chunxugou_Animal()
	{
		cout << "���๹�캯��" << endl;
	}
	//���������������������ָ���ͷŶ���ʱ���ɾ�������
	/*virtual~chunxugou_Animal()
	{
		cout << "������������" << endl;
	} */
	virtual~chunxugou_Animal() = 0;//��������������ʵ�֣���Ϊ������Ҳ��Ҫ�ͷŶ��Ͽ��ٵĿռ�
	virtual void speak() = 0;
};
chunxugou_Animal::~chunxugou_Animal()
{
	cout << "���ി����������" << endl;
}
class chunxugou_Cat:public chunxugou_Animal
{
public:
	chunxugou_Cat(string name)
	{
		cout << "cat ����" << endl;
		m_Name = new string(name);
	}
	~chunxugou_Cat()
	{
		cout << "cat ����" << endl;
		if (m_Name!=NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_Name <<" speak" << endl;
	}
	string * m_Name;
};

void chunxugou_test01()
{
	chunxugou_Animal * a = new chunxugou_Cat("Tom");
	a->speak();
	delete a;//����ָ��������ʱ�������������������������������ж��������ԣ�������ڴ�й©
}

void main_chunxuhanshu()
{
	chunxugou_test01();
}