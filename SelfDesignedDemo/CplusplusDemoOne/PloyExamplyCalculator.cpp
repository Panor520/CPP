#include <iostream>
using namespace std;


//多态优点：
/*可读性强
组织结构清晰
可维护性高*/
class PloyCalculator
{
public:
    virtual int	getResult()
	{
		return 0;
	}
	int A;
	int B;
};

class PloyAdd :public PloyCalculator
{
	int	getResult()
	{
		return A+B;
	}
};

class PloySub :public PloyCalculator
{
	int	getResult()
	{
		return A - B;
	}
};

class PloyMul :public PloyCalculator
{
	int	getResult()
	{
		return A * B;
	}
};


void ploycalculatortest01()
{
	PloyCalculator * pc=new  PloyAdd;//new 出来的都是指针地址，前面要用指针获取
	pc->A = 1;
	pc->B = 2;
	cout << pc->getResult() << endl;
	delete pc;

	pc = new PloySub;
	pc->A = 2;
	pc->B = 4;
	cout << pc->getResult() << endl;
	delete pc;

	pc = new PloyMul;
	pc->A = 2;
	pc->B = 3;
	cout << pc->getResult() << endl;
	delete pc;
}

void main_PloyCalculator()
{
	ploycalculatortest01();
}