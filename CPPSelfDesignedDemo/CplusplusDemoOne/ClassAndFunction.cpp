#include <iostream>
using namespace std;
//Ĭ������£�������г�Ա����˽�е�.ֻ�������Ԫ�������Է���˽�г�Ա
//protected���ܱ�������Ա�������ࣨ�����ࣩ���ǿɷ��ʵ�
class Box
{
public:
	double length; 
	double Width;
	double GetStr(void)//�޲������Լ�void��
	{
		return (length + Width)*2;
	}
	double GetArea();//�޲���Ҳ���Բ���void��
};
//��̳�
class BoxOne :protected Box
{
	double x;//��ָ�����ʷ���Ĭ����Private.
};

double Box::GetArea()
{
	return length * Width;
}

//���캯���������������Լ��������������Զ����ɿյġ�
//���캯���������֣��вι��캯�����޲ι��캯��
//���캯�������ͷ֣���ͨ���캯���Ϳ������캯�������ǿ������캯���Ķ�����ͨ���캯��
class Apple
{
public:
	Apple(double len);//���캯���������޷���ֵ�������Դ�������������
	~Apple();//���������������޷���ֵ�����޲���;�����ͷ���Դ����������
	Apple(const Apple &a)//�������캯��������һ����������Ը�����������Ҫ�����õķ�ʽ���ã�Ϊ�˱�֤���ı�ԭʼ�����ֵ�����Լ���const����
	{
		cout << "���ǿ������캯����" << endl;
		length = a.length;
	}
	double length;
};

Apple::Apple(double len=0)
{//���캯���������ʱ����
	cout << "���ǹ��캯����" << endl;
	length = len;
}

Apple::~Apple()
{//�������������˳�ʱ���У�����������ʱִ��
	cout << "����������������������ʱ���ã�" << endl;
}

//�ඨ���еĶ���ĺ�������������������ʹû��ʹ�� inline ˵������

//��������
class Mobkey
{
	void printf(int x)
	{
		cout << "����X=" << x << endl;
	}
	void printf(double x)
	{
		cout << "������=" << x << endl;
	}
};

//���������
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

	Apple apple;//���������ڶ�������ʱִ�У����˺���ִ����Ż�����Apple���󣬹�Apple�е����������������ִ�С�
	apple.length = 10;
	cout << "Apple.Length:" << apple.length << endl;
	cout << "Test ����˳��" << endl;

	//���ù��캯������
	//1.���ŷ�
	Apple apple1(10);
	Apple apple6();//����ǲ���ȷ�ģ��ᱻ����Ϊһ����������
	//2.��ʾ�� ע�⣺�����ÿ���������ʼ����������
	Apple apple2 = Apple(10);//Apple(10);��һ���������󣬵�ǰ��ִ����ϻ�����������
	Apple apple3 = Apple(apple2);

	//Apple(apple3);//�������Ὣ���д��뷭��Ϊ Apple apple3;�ͺ������apple3�������ظ��� 
	//3.��ʽת����
	Apple apple4 = 10;//��ͬ�� Apple apple4=Apple(10);
	Apple apple5 = apple4;//��ͬ�� Apple apple5= Apple(apple4);

	//���������
	BoxThree bt3,bt4,bt5;
	bt3.length = 1;
	bt3.Width = 2;
	bt4.length = 2;
	bt4.Width = 3;
	bt5 = bt3 + bt4;
	cout << "���ؽ����" << endl;
	cout << "length=" << bt4.length << endl;
	cout << "Width=" << bt4.Width << endl;
}
/// <summary>
/// ��ʼ��������Ե����ַ�ʽ
/// </summary>
class InitializationList
{
public:
	////��ͨ����ʼֵ
	//InitializationList(int a,int b)
	//{
	//	A = a;
	//	B = b;
	//}
	//��ʼ���б���ʼֵ
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
		//b = 10;//��̬����ֻ�ܷ��ʾ�̬��Ա
		cout<<"��̬������ֵA="<<a << endl;
	}
	static int a;
	int b;
private:
	static void func2()
	{
		cout << "��̬����2" << a << endl;
	}
};
//x�ȸ���ʼֵ
int Applecaf1::a = 10;
void testcaf3()
{
	Applecaf1 a;
	a.func();

	//Applecaf1::func();
	//Applecaf::func2();//��̬����ӵ�з���Ȩ��
}
//��Ա�����ͳ�Ա�����ֿ��洢
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
	void func(){}//ÿ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ���Ƕ��ͬ���Ͷ���Ṳ��һ����룬��thisָ�������ĸ�������øú���
	static void func1(){}
};
void testcaf4()
{
	Applecaf2 a;
	cout << "sizeof=" << sizeof(a) << endl;//���Ϊ1�����ͣ� �������ǿ�ʱ��sizeofΪ1���ֽڣ��洢�����ַ

	Applecaf3 b;
	cout << "sizeof=" << sizeof(b) << endl;//���Ϊ4�����ͣ���ֻ�г�Ա����ʱ��sizeofΪ��Ա�����Ĵ�С

	Applecaf4 c;
	cout << "sizeof=" << sizeof(c) << endl;//���Ϊ8�����ͣ�ֻ�зǾ�̬��Ա�����洢����Ķ�����
}
//
class Applecaf5
{
public:
	Applecaf5(int age)
	{
		age = age;//�����ֵ��û�и�����������ԣ����Ǹ������β��Լ�
		this->age = age;//ʹ��thisָ�������������Ը�ֵ�����⡣
	}
	Applecaf5& addage(Applecaf5 & a)//������������Ϊ&���򲻻Ὣ���������
	{
		this->age += a.age;
		return *this;
	}
	Applecaf5 addage1(Applecaf5& a)//�������Ͷ���һ���µ�Applecaf5���󣬶�����֮ǰ�Ķ���
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
	a1.addage1(b).addage1(b).addage1(b);//������������Ϊ&���򲻻Ὣ���������
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
