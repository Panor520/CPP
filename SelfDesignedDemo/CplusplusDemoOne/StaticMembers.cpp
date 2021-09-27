#include <iostream>
using namespace std;

//静态变量初始化不能被放在类的定义中，但可以在类的外部使用::初始化。
//在创建第一个对象时，所有的静态数据都会被初始化为零.
//静态变量初始化在类内不好使，一定在类外。
class box
{
public:
	static int count;
	box(void)
	{
		cout << "count=" << count << endl;
	}

	static void getcount()
	{
		cout << "count=" << count+1 << endl;
	}
};
int box::count = 1;

//静态成员只需要通过 类名::静态成员名 就可以访问，无需创建对象。
int mainsm()
{
	cout << "count=" << box::count << endl;
	box::getcount();
	box();//构造函数被调用前，类外的静态变量赋值过程就已被调用。
	return 0;
}