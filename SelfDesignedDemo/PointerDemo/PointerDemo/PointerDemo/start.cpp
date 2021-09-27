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

//指针变量作为参数
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
{	//new出的数据在堆上，由程序员自行管理
	//new 出来的是该类型的指针，接收的指针变量类型要和new 后的类型相同
	int* a = new int(10);
	double* b = new double(11);
	cout << *a << endl;
	cout << *b << endl;
	cout << a << endl;
	//将开辟的内存释放
	delete a;
	//cout << *a << endl;//运行时会报错，因为已经被释放了
	cout << a << endl;//new出的内存地址被释放后指向00008123
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
	//特别注意，释放数组时要在delete后加[]符号
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

	////常量指针
	//const int* e = &a;
	//int aa = 100;

	//e = &aa;
	////*e = 100;//error 指针中地址对应的值不能修改
	//cout << *e << endl;

	////指针常量
	//int * const ee = &a;
	////ee = &aa;//error 指针中的地址不能修改
	//*ee = 1000;

	//const int* const eee = &a;
	////eee = &aa;//Error
	////*eee = 101;//error 

	//int arr[] = { 1,3,2 };
	//cout << arr[0] << endl;
	//cout << *arr << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << *(arr+i) << endl;//偏移一个int型的i就是数组首地址加4，刚好得到第二个元素的首地址
	//}

#pragma endregion


}