#include <iostream>
using namespace std;

//���裺��ˮ ���� ����ˮ�� ����ţ��
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
		cout << "��ˮ" << endl;
	}
	virtual void chongpao()
	{
		cout << "�ݲ�" << endl;
	}
	virtual void daoru()
	{
		cout << "���뱭��" << endl;
	}
	virtual void jiazuoliao()
	{
		cout << "����" << endl;
	}
};

class Abstract_Coffee :public Abstract_Drinking
{
	virtual void boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void chongpao()
	{
		cout << "�ݿ���" << endl;
	}
	virtual void daoru()
	{
		cout << "���뱭��" << endl;
	}
	virtual void jiazuoliao()
	{
		cout << "��ţ��" << endl;
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