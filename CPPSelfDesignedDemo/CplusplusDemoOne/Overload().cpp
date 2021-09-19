#include <string>
#include <iostream>
using namespace std;


class KuohaoPerson
{
public :
	void operator()(string text)
	{
		cout << text << endl;
	}
	int operator()(int a,int b)
	{
		return a + b;
	}
};

//成员函数的重载，作用域只在该类的对象下
class KuohaoPerson1
{
};

void main_oVERLOAD()
{
	KuohaoPerson ko;
	ko("xxx");//这样类似函数的调用的重载就是仿函数。

	cout<< KuohaoPerson()(1, 2)<<endl;//KuohaoPerson()就是创建匿名对象
	/*KuohaoPerson1 ko1;
	ko1("xaws ");*/
}