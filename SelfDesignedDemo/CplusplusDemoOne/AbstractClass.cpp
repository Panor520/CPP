#include <string>
#include <iostream>
using namespace std;

//ֻҪ��һ�����麯���������ͽ���������
class AbstractAnimal
{
public:
	virtual void speak()=0;//���麯����û�к����壬ֱ����=0��ʾ
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