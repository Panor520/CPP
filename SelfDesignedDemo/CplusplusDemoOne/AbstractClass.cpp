#include <string>
#include <iostream>
using namespace std;

//只要有一个纯虚函数，这个类就叫做抽象类
class AbstractAnimal
{
public:
	virtual void speak()=0;//纯虚函数，没有函数体，直接用=0表示
};

class AbstractCat:public AbstractAnimal
{
	virtual void speak()
	{
		cout << "cat speak" << endl;
	};
};

void abstracttest01()
{
	AbstractAnimal* cat=new AbstractCat;
	cat->speak();
}

void main_Abstract()
{
	abstracttest01();
}