#include <string>
#include <iostream>
using namespace std;

template <class T>
class templateInheritBase
{
public:
	T m;
};

//class templateInheritSon :public templateInheritBase//error,����ָ��������T�����ͣ����ܼ̳и�����
class templateInheritSon :public templateInheritBase<int>
{

};

//�����Ҫ���ָ��������T���ͣ�����Ҳ��Ҫ����ģ��
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