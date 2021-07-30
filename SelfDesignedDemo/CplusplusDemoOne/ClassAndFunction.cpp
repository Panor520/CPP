#include <iostream>
using namespace std;
//默认情况下，类的所有成员都是私有的.只有类和友元函数可以访问私有成员
//protected（受保护）成员在派生类（即子类）中是可访问的
class Box
{
public:
	double length; 
	double Width;
	double GetStr(void)//无参数可以加void，
	{
		return (length + Width)*2;
	}
	double GetArea();//无参数也可以不加void，
};
//类继承
class BoxOne :protected Box
{
	double x;//不指定访问符，默认是Private.
};

double Box::GetArea()
{
	return length * Width;
}

//构造函数和析构函数不自己声明编译器会自动生成空的。
//构造函数按参数分：有参构造函数和无参构造函数
//构造函数按类型分：普通构造函数和拷贝构造函数；不是拷贝构造函数的都是普通构造函数
class Apple
{
public:
	Apple(double len);//构造函数声明；无返回值；但可以带参数；可重载
	~Apple();//析构函数声明；无返回值；且无参数;用于释放资源；不可重载
	Apple(const Apple &a)//拷贝构造函数：将另一个对象的属性赋给本对象，且要以引用的方式引用，为了保证不改变原始对象的值，所以加了const修饰
	{
		cout << "这是拷贝构造函数！" << endl;
		length = a.length;
	}
	double length;
};

Apple::Apple(double len=0)
{//构造函数是类进入时进行
	cout << "这是构造函数！" << endl;
	length = len;
}

Apple::~Apple()
{//析构函数是类退出时进行，即对象销毁时执行
	cout << "这是析构函数！对象被销毁时调用！" << endl;
}

//类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。

//函数重载
class Mobkey
{
	void printf(int x)
	{
		cout << "整数X=" << x << endl;
	}
	void printf(double x)
	{
		cout << "浮点数=" << x << endl;
	}
};

//运算符重载
class BoxThree :public Box
{
public:
	BoxThree operator+(Box b)
	{
		BoxThree bt;
		bt.length = this->length + b.length;
		bt.Width = this->Width + b.Width;
		return bt;
	}
};

void testcaf1()
{
	Box box1;
	double area,str;
	box1.length = 2;
	box1.Width = 4;
	area = box1.GetArea();
	str = box1.GetStr();
	cout << "Area:" << area << endl;
	cout << "str:" << str << endl;

	Apple apple;//析构函数在对象销毁时执行，当此函数执行完才会销毁Apple对象，故Apple中的析构函数总是最后执行。
	apple.length = 10;
	cout << "Apple.Length:" << apple.length << endl;
	cout << "Test 析构顺序！" << endl;

	//调用构造函数方法
	//1.括号法
	Apple apple1(10);
	Apple apple6();//这个是不正确的，会被编译为一个函数声明
	//2.显示法 注意：不能用拷贝函数初始化匿名对象
	Apple apple2 = Apple(10);//Apple(10);是一个匿名对象，当前行执行完毕会立即被回收
	Apple apple3 = Apple(apple2);

	//Apple(apple3);//编译器会将这行代码翻译为 Apple apple3;就和上面的apple3对象名重复了 
	//3.隐式转换法
	Apple apple4 = 10;//等同于 Apple apple4=Apple(10);
	Apple apple5 = apple4;//等同于 Apple apple5= Apple(apple4);

	//运算符重载
	BoxThree bt3,bt4,bt5;
	bt3.length = 1;
	bt3.Width = 2;
	bt4.length = 2;
	bt4.Width = 3;
	bt5 = bt3 + bt4;
	cout << "重载结果：" << endl;
	cout << "length=" << bt4.length << endl;
	cout << "Width=" << bt4.Width << endl;
}
/// <summary>
/// 初始化类的属性的两种方式
/// </summary>
class InitializationList
{
public:
	////普通赋初始值
	//InitializationList(int a,int b)
	//{
	//	A = a;
	//	B = b;
	//}
	//初始化列表赋初始值
	InitializationList(int a, int b) :A(a),B(b)
	{

	}
	int A;
	int B;
};

void testcaf2()
{
	InitializationList p(1,2);
	cout << p.A<<"--"<<p.B << endl;
}

class Applecaf1
{
public:
	static void func()
	{
		a = 100;
		//b = 10;//静态函数只能访问静态成员
		cout<<"静态函数赋值A="<<a << endl;
	}
	static int a;
	int b;
private:
	static void func2()
	{
		cout << "静态函数2" << a << endl;
	}
};
//x先赋初始值
int Applecaf1::a = 10;
void testcaf3()
{
	Applecaf1 a;
	a.func();

	//Applecaf1::func();
	//Applecaf::func2();//静态函数拥有访问权限
}
//成员变量和成员函数分开存储
class Applecaf2
{

};
class Applecaf3
{
	int x;
};
class Applecaf4
{
	int x;
	int y;
	static int b;
	void func(){}//每个非静态成员函数只会诞生一份函数实例，也就是多个同类型对象会共用一块代码，用this指针区分哪个对象调用该函数
	static void func1(){}
};
void testcaf4()
{
	Applecaf2 a;
	cout << "sizeof=" << sizeof(a) << endl;//输出为1；解释： 当对象是空时，sizeof为1个字节，存储对象地址

	Applecaf3 b;
	cout << "sizeof=" << sizeof(b) << endl;//输出为4；解释：当只有成员变量时，sizeof为成员变量的大小

	Applecaf4 c;
	cout << "sizeof=" << sizeof(c) << endl;//输出为8；解释：只有非静态成员变量存储在类的对象上
}
//
class Applecaf5
{
public:
	Applecaf5(int age)
	{
		age = age;//这个赋值并没有赋给下面的属性，而是赋给了形参自己
		this->age = age;//使用this指针避免上面给属性赋值的问题。
	}
	Applecaf5& addage(Applecaf5 & a)//返回类型若不为&，则不会将年龄多次相加
	{
		this->age += a.age;
		return *this;
	}
	Applecaf5 addage1(Applecaf5& a)//返回类型都是一个新的Applecaf5对象，而不是之前的对象
	{
		this->age += a.age;
		return *this;
	}
	int age;
};

void testcaf5()
{
	Applecaf5 a(10);
	Applecaf5 a1(10);
	Applecaf5 b(10);

	a.addage(b).addage(b).addage(b);
	a1.addage1(b).addage1(b).addage1(b);//返回类型若不为&，则不会将年龄多次相加
	cout << "a.age=" << a.age << endl;
	cout << "a1.age1=" << a1.age << endl;
}

int mainCAF()
{
	//test1();
	//testcaf2();
	//testcaf3();
	//testcaf4();
	testcaf5();
	return 0;
}
