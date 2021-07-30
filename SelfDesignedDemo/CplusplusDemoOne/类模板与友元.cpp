#include <iostream>
#include <string>
using namespace std;

#pragma region ①和②
//下面的①和②要在全局函数类外实现前实现
//①
template <typename T1, typename T2>
class ClassTemplateFriend;
//②
template <typename T1, typename T2>
void PrintPerson2(ClassTemplateFriend<T1, T2> p)
{
	cout << p.Name << " " << p.Age << endl;
}
#pragma endregion


template <typename T1,typename T2>
class ClassTemplateFriend
{
	//全局函数 类内实现
	friend void PrintPerson(ClassTemplateFriend<T1,T2> p)
	{
		cout << p.Name << " " << p.Age << endl;
	}
	//全局函数 类外实现
	//1.加空模板参数列表 如下
	//2.如果全局函数是类外实现，需要让编译器提前知道这个函数的存在 否则编译不过去 如①和②
	friend void PrintPerson2<>(ClassTemplateFriend<T1, T2> p);
public:
	ClassTemplateFriend(T1 name, T2 age)
	{
		this->Name = name;
		this->Age = age;
	}
	

private:
	T1 Name;
	T2 Age;
};


void ClassTemplateFriendcc()
{
	ClassTemplateFriend<string, int> ctf("类内实现",19);
	PrintPerson(ctf);
}

void ClassTemplateFriendcd()
{
	ClassTemplateFriend<string, int> ctf("类外实现", 199);
	PrintPerson2(ctf);
}

void main_ClassTemplateFriendcd()
{
	//ClassTemplateFriendcc();
	ClassTemplateFriendcd();
}