#include <iostream>
using namespace std;

class father
{
public:
	father()
	{
		cout << "father Constructor" << endl;
	}
	~father()
	{
		cout << "father Constructor" << endl;
	}

	int A;
protected:
	int B;
private:
	int C;
};

class son :public father
{
public:
	son()
	{
		cout << "son Constructor" << endl;
	}
	~son()
	{
		cout << "son Constructor" << endl;
	}

	int D;
};

//创建时是先创建基类
//销毁时是先销毁派生类
void main_Classmodel()
{
	son s;
	cout << sizeof(s) << endl;//16 private的成员也被继承下来了，但是被隐藏掉了
}

