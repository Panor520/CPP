#include <iostream>
using namespace std;


//��̬�ŵ㣺
/*�ɶ���ǿ
��֯�ṹ����
��ά���Ը�*/
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
	PloyCalculator * pc=new  PloyAdd;//new �����Ķ���ָ���ַ��ǰ��Ҫ��ָ���ȡ
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