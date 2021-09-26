//函数内部声明的所有变量都将占用栈内存
//这是程序未使用的内存，在程序运行时用于动态分配内存。
//使用特殊的运算符为给定类型的变量在运行时分配堆内的内存，这会返回所分配的空间地址。这种运算符即 new 运算符。
//如果您不再需要动态分配的内存空间，可以使用 delete 运算符，删除之前由 new 运算符分配的内存。
//new 与 malloc() 函数相比，其主要的优点是，new 不只是分配了内存，它还创建了对象。
#include <iostream>
using namespace std;

class Box
{
public:
	Box() { cout << "这是构造函数！" << endl; }
	~Box() { cout<<"这是析构函数" << endl; }
};

void memory()
{
	double* pvalue = NULL;//初始化为NULL指针
	pvalue = new double;//为变量分配内存（请求地址）
	*pvalue = 1.23;
	cout << "pvalue=" << *pvalue << endl;
	delete pvalue;//释放内存

	char* pvalue1 = NULL;
	pvalue1 = new char[20];
	strcpy(pvalue1, "haha");
	cout << pvalue1 << endl;
	delete[] pvalue1;


	int m = 10;
	// 动态分配,数组长度为 m;
	int* array = new int[m];//声明数组时必须指定数组长度

	//释放内存
	delete[] array;

	//对象的动态内存分配和数据类型一样，没什么不同
	Box* box = new Box[2];//两个Box对象，故析构和构造函数分别被调用两次
	delete[]box;
}

int* newGrammar()
{
	//new 在堆区创建数据，并返回该类型的指针,需要自己释放
	int* p = new int(10);
	return p;
}

void newArray()
{
	int* p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = 100 + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<*(p+i) <<endl;
	}
	//释放数组加[]
	delete[] p;
}

int* testStack()
{
	int p = 10;
	return &p;
}

void testRelease()
{
	int* a = testStack();
	cout << *a << endl;//第一次编译器会保留地址
	cout << *a << endl;//后面的就会自动释放掉栈区的数据
	cout << *a << endl;
	cout << *a << endl;

	int * p= newGrammar();
	cout << *p <<endl ;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//释放堆区数据使用delete
	delete p;
	//cout << *p << endl;//上面释放完，这个地方就会报错
}


void mainme()
{
	//memory();
	//testRelease();
	newArray();
}
