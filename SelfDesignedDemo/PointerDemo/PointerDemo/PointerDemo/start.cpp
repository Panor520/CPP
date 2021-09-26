#include <iostream>
using namespace std;


void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "Swap a " << &a << endl;
	cout << "Swap b " << &b << endl;
	cout << "Swap a " << a << endl;
	cout << "Swap b " << b << endl;
}

//ָ�������Ϊ����
void Swap(int* a, int* b)
{
	cout << "Swap a " << a << endl;
	cout << "Swap b " << b << endl;
	cout << "Swap a " << *a << endl;
	cout << "Swap b " << *b << endl;
	cout << "Swap &a " << &a << endl;
	cout << "Swap &b " << &b << endl;
	int* temp = a;
	a = b;
	b = temp;
	cout << "Swap &a " << &a << endl;
	cout << "Swap &b " << &b << endl;
	cout << "Swap a " << a << endl;
	cout << "Swap b " << b << endl;
	cout << "Swap a " << *a << endl;
	cout << "Swap b " << *b << endl;
}

void Swap1(int& a, int& b)
{
	cout << " &a " << &a << endl;
	cout << " &b " << &b << endl;
	cout << " a " << a << endl;
	cout << " b " << b << endl;
	int temp = a;
	a = b;
	b = temp;
}
void Swap11(int*& a, int*& b)
{
	cout << " &a " << &a << endl;
	cout << " &b " << &b << endl;
	cout << " a " << a << endl;
	cout << " b " << b << endl;
	int* temp = a;
	a = b;
	b = temp;
	cout << " &a " << &a << endl;
	cout << " &b " << &b << endl;
	cout << " a " << a << endl;
	cout << " b " << b << endl;
}

class Person
{
public:
	Person(int age, int c)
	{
		this->age = age;
		this->c = c;
	}
	void Show()
	{
		cout << this << endl;
		cout << &this->age << endl;
		cout << &this->c << endl;
	}
	Person Return()
	{
		return *this;
	}
	Person& Return1()
	{
		return *this;
	}
private:
	int age;
	int c;
};

void TestNew()
{	//new���������ڶ��ϣ��ɳ���Ա���й���
	//new �������Ǹ����͵�ָ�룬���յ�ָ���������Ҫ��new ���������ͬ
	int* a = new int(10);
	double* b = new double(11);
	cout << *a << endl;
	cout << *b << endl;
	cout << a << endl;
	//�����ٵ��ڴ��ͷ�
	delete a;
	//cout << *a << endl;//����ʱ�ᱨ����Ϊ�Ѿ����ͷ���
	cout << a << endl;//new�����ڴ��ַ���ͷź�ָ��00008123
}

void TestNewArr()
{	
	int* p = new int[9];
	for (int i = 0; i < 9; i++)
	{
		*(p + i) = i;
	}
	for (int i = 0; i < 9; i++)
	{
		cout << *(p + i) << endl;
	}
	//�ر�ע�⣬�ͷ�����ʱҪ��delete���[]����
	delete[] p;
	cout << p << endl;
}

void main()
{
	TestNew();
	TestNewArr();
	/*Person p(1,2);
	p.Show();

	p.Return().Show();
	p.Return1().Show();*/

#pragma region TestSwap

	//int a = 11;
	//int b = 22;
	////Swap(a,b);
	////Swap(&a,&b);
	////Swap1(a,b);
	//int* c = &a;
	//int* d = &b;
	//Swap11(c, d);

	//cout << " &c " << &c << endl;
	//cout << " &d " << &d << endl;
	//cout << " a " << a << endl;
	//cout << " b " << b << endl;


	//int a = 10;
	//int* b = &a;

	////����ָ��
	//const int* e = &a;
	//int aa = 100;

	//e = &aa;
	////*e = 100;//error ָ���е�ַ��Ӧ��ֵ�����޸�
	//cout << *e << endl;

	////ָ�볣��
	//int * const ee = &a;
	////ee = &aa;//error ָ���еĵ�ַ�����޸�
	//*ee = 1000;

	//const int* const eee = &a;
	////eee = &aa;//Error
	////*eee = 101;//error 

	//int arr[] = { 1,3,2 };
	//cout << arr[0] << endl;
	//cout << *arr << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << *(arr+i) << endl;//ƫ��һ��int�͵�i���������׵�ַ��4���պõõ��ڶ���Ԫ�ص��׵�ַ
	//}

#pragma endregion


}