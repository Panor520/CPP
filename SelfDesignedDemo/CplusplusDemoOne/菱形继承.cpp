#include <iostream>
using namespace std;

//菱形继承主要问题是子类继承两份相同数据，导致资源浪费以及毫无意义
//利用虚继承解决上述问题
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
	//tuo.age = 10;//Error 继承的二义性问题
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

//virtual修饰的继承，是将重复的属性定义为一个vbptr
void lingxingtest02()
{
	lingxingSheepTuo1 tuo;
	tuo.age = 10;//利用virtual解决二义性问题
	cout<<tuo.age <<endl;
	
	tuo.lingxingSheep1::age = 10;
	tuo.lingxingTuo1::age = 120;
	//上面的两次赋值其实操作的是同一个地址的值，如下输出
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
