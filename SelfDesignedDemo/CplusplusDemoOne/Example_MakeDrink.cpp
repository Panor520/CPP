#include <iostream>
using namespace std;

//步骤：煮水 冲泡 倒入水中 加糖牛奶
class Abstract_Drinking
{
public:
	virtual void boil() = 0;
	virtual void chongpao() = 0;
	virtual void daoru() = 0;
	virtual void jiazuoliao() = 0;

	void drink()
	{
		boil();
		chongpao();
		daoru();
		jiazuoliao();
	}
};

class Abstract_Tea:public Abstract_Drinking
{
	virtual void boil()
	{
		cout << "煮水" << endl;
	}
	virtual void chongpao()
	{
		cout << "泡茶" << endl;
	}
	virtual void daoru()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void jiazuoliao()
	{
		cout << "加糖" << endl;
	}
};

class Abstract_Coffee :public Abstract_Drinking
{
	virtual void boil()
	{
		cout << "煮水" << endl;
	}
	virtual void chongpao()
	{
		cout << "泡咖啡" << endl;
	}
	virtual void daoru()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void jiazuoliao()
	{
		cout << "加牛奶" << endl;
	}
};

void Dodrink(Abstract_Drinking * ad)
{
	ad->drink();
}

void main_MakeDrink()
{
	Dodrink(new Abstract_Tea);
	Dodrink(new Abstract_Coffee);
}