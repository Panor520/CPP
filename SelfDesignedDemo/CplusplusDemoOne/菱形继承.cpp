#include <iostream>
using namespace std;

//���μ̳���Ҫ����������̳�������ͬ���ݣ�������Դ�˷��Լ���������
//������̳н����������
class LingxingAnimal
{
public:
	int age;
};
class lingxingSheep:public LingxingAnimal{};
class lingxingTuo:public LingxingAnimal{};
class lingxingSheepTuo :public lingxingSheep, public lingxingTuo{};

void lingxingtest01()
{
	lingxingSheepTuo tuo;
	//tuo.age = 10;//Error �̳еĶ���������
	tuo.lingxingSheep::age = 10;
	tuo.lingxingTuo::age = 12;
	cout<< tuo.lingxingSheep::age <<endl;
	cout<< tuo.lingxingTuo::age <<endl;
}

class LingxingAnimal1
{
public:
	int age;
};
class lingxingSheep1 :virtual public LingxingAnimal1 {};
class lingxingTuo1 :virtual public LingxingAnimal1 {};
class lingxingSheepTuo1 :virtual public lingxingSheep1, public lingxingTuo1 {};

//virtual���εļ̳У��ǽ��ظ������Զ���Ϊһ��vbptr
void lingxingtest02()
{
	lingxingSheepTuo1 tuo;
	tuo.age = 10;//����virtual�������������
	cout<<tuo.age <<endl;
	
	tuo.lingxingSheep1::age = 10;
	tuo.lingxingTuo1::age = 120;
	//��������θ�ֵ��ʵ��������ͬһ����ַ��ֵ���������
	cout << &tuo.lingxingSheep1::age << endl;
	cout << &tuo.lingxingTuo1::age << endl;

	cout << tuo.lingxingSheep1::age << endl;
	cout << tuo.lingxingTuo1::age << endl;
}


void main_lingxingjicheng()
{
	lingxingtest01();
	lingxingtest02();
}
