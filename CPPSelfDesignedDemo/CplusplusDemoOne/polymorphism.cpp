//多态分为两类：
//静态多态：函数重载、运算符重载，复用函数名
//动态多态：派生类和虚函数（重写）实现运行时多态
//区别：
//静态多态的函数地址早绑定-编译阶段确定函数地址
//动态多态的函数地址晚绑定-运行阶段确定函数地址

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
	void speak()//重写（函数名，参数列表与基类完全一致）
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
	ploySpeak(cat);//调用时，优先执行子类中的speak,叫做重写（函数名，参数列表完全一致）
}

void main_ploybase()
{
	ploytest01();
}