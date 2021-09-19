#include <iostream>
using namespace std;

#pragma region BaseClass
class zuzhuang_CPU
{
public:
	virtual void calculate() = 0;
};

class zuzhuang_VideoCard
{
public:
	virtual void Display() = 0;
};

class zuzhaung_Memory
{
public:
	virtual void storage() = 0;
};
#pragma endregion

#pragma region Computer

class zuzhuang_Computer
{
public:
	zuzhuang_Computer(zuzhuang_CPU* cpu, zuzhuang_VideoCard* vc, zuzhaung_Memory* m)
	{
		this->cpu = cpu;
		this->vc = vc;
		this->mem = m;
	}
	~zuzhuang_Computer()
	{
		if (this->cpu!=NULL)
		{
			delete this->cpu;
			this->cpu = NULL;
		}
		if (this->vc != NULL)
		{
			delete this->vc;
			this->vc = NULL;
		}
		if (this->mem != NULL)
		{
			delete this->mem;
			this->mem = NULL;
		}
	}
	void work()
	{//调用接口
		cpu->calculate();
		vc->Display();
		mem->storage();
	}
private:
	zuzhuang_CPU* cpu;
	zuzhuang_VideoCard* vc;
	zuzhaung_Memory* mem;
};

#pragma endregion

#pragma region Intel
class zuzhuang_CPU_Intel :public zuzhuang_CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel calculate" << endl;
	}
};

class zuzhuang_VideoCard_Intel:public zuzhuang_VideoCard
{
public:
	virtual void Display()
	{
		cout << "Intel Display " << endl;
	}
};

class zuzhuang_Memory_Intel :public zuzhaung_Memory
{
public:
	virtual void storage()
	{
		cout << "Intel storage" << endl;
	}
};
#pragma endregion

#pragma region Lenvo

class zuzhuang_CPU_Lenvo :public zuzhuang_CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenvo calculate" << endl;
	}
};

class zuzhuang_VideoCard_Lenvo :public zuzhuang_VideoCard
{
public:
	virtual void Display()
	{
		cout << "Lenvo Display " << endl;
	}
};

class zuzhuang_Memory_Lenvo :public zuzhaung_Memory
{
public:
	virtual void storage()
	{
		cout << "Lenvo storage" << endl;
	}
};
#pragma endregion

void zuzhuang_test01()
{
	//一台电脑零件
	zuzhuang_CPU* intel_cpu = new zuzhuang_CPU_Intel;
	zuzhaung_Memory* intel_me = new zuzhuang_Memory_Intel;
	zuzhuang_VideoCard* intel_vc = new zuzhuang_VideoCard_Intel;
	//一台电脑
	cout << "第一台电脑：" << endl;
	zuzhuang_Computer * cp = new zuzhuang_Computer(intel_cpu, intel_vc, intel_me);
	cp->work();
	delete cp;
	cout << endl;

	//第二台电脑
	cout << "第二台电脑：" << endl;
	zuzhuang_Computer* cp1 = new zuzhuang_Computer(new zuzhuang_CPU_Lenvo, new zuzhuang_VideoCard_Lenvo, new zuzhuang_Memory_Lenvo);
	cp1->work();
	delete cp1;
	cout << endl;

	//第三台电脑
	cout << "第三台电脑：" << endl;
	zuzhuang_Computer* cp2 = new zuzhuang_Computer(new zuzhuang_CPU_Lenvo, new zuzhuang_VideoCard_Intel, new zuzhuang_Memory_Lenvo);
	cp2->work();
	delete cp2;
}

void main_zuzhuang()
{
	zuzhuang_test01();
}