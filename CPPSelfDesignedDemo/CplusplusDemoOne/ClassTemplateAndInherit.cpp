#include <string>
#include <iostream>
using namespace std;

template <class T>
class templateInheritBase
{
public:
	T m;
};

//class templateInheritSon :public templateInheritBase//error,必须指定父类中T的类型，才能继承给子类
class templateInheritSon :public templateInheritBase<int>
{

};

//如果想要灵活指定父类中T类型，子类也需要变类模板
template <class T1,class T2>
class templateInheritSon2 :public templateInheritBase<T1>
{
public:
	templateInheritSon2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T2 obj;
};

void InheritTest01()
{
	templateInheritBase<int>* tib = new templateInheritSon2<int,string>();
	cout<<typeid(tib->m).name()<<endl;
	templateInheritSon2<int, string>* s = new templateInheritSon2<int,string>();
	cout << typeid(s->m).name() << endl;
	cout << typeid(s->obj).name() << endl;
}

void main_TemplateInherit()
{
	InheritTest01();
}