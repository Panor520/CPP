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

//����ʱ���ȴ�������
//����ʱ��������������
void main_Classmodel()
{
	son s;
	cout << sizeof(s) << endl;//16 private�ĳ�ԱҲ���̳������ˣ����Ǳ����ص���
}

