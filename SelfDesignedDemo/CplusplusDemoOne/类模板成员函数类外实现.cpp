#include <string>
using namespace std;
#include <iostream>
template <typename T1,class T2>
class classTemplatePersonFunc33
{
public:
	classTemplatePersonFunc33(T1 name, T2 age);
	/*{
		this->Name = name;
		this->Age = age;
	}*/
	void showPerson()
	{
		cout << this->Name << " " << this->Age << endl;
	}
	void showPerson1();
	T1 Name;
	T2 Age;
};

template <typename T1, class T2>
classTemplatePersonFunc33<T1, T2>::classTemplatePersonFunc33(T1 name, T2 age)
{
	this->Name = name;
	this->Age = age;
}
template <typename T1, class T2>
void classTemplatePersonFunc33<T1, T2>::showPerson1()
{
	cout << this->Name << " 11 " << this->Age << endl;
}


void main_PersonFunc33()
{
	classTemplatePersonFunc33<string, int> ctp("haha",19);
	ctp.showPerson1();
	ctp.showPerson();
}