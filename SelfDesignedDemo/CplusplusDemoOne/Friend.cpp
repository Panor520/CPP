#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Building
{
	friend class GoodGay;//friend class
	friend void F_Visit();//friend Global function

public:
	Building();
	
public :
	string Room_Sitting;
private :
	string	Room_Bed;
};

Building::Building()
{
	this->Room_Bed = "Bed";
	this->Room_Sitting = "Sitting";
}

void F_Visit()
{
	Building b;
	cout<<"Global Friend Visit Room_"<< b.Room_Sitting<<endl;
	//cout << "Visit Room_" << b.Room_Bed << endl;
}

void F_Visit2()
{
	Building b;
	cout << "Global Friend Visit Room_" << b.Room_Sitting << endl;
	//cout << "Visit Room_" << b.Room_Bed << endl;//b.Room_Bed;//can't get this 
}


class GoodGay
{

public:
	GoodGay()
	{
		b = new Building;//New create object get pointer
	}
	void visit()
	{
		cout << "Class Friend Visit Room_" << b->Room_Sitting << endl;
		cout << "class Friend Visit Room_" << b->Room_Bed << endl;
	}
	Building* b;
};

class Building1;
class goodgay1
{
public:
	goodgay1();

	void visit();//可访问Building中的私有成员

	void visit1();//不可访问Building中的私有成员

	Building1* building;
};

class Building1
{
	friend void goodgay1::visit();
public:
	Building1();

public:
	string Room_Sitting;
private:
	string	Room_Bed;
};


Building1::Building1()
{
	this->Room_Bed = "Bed";
	this->Room_Sitting = "Sitting";
}

goodgay1::goodgay1()
{
	building = new Building1;
}
void goodgay1::visit()
{
	cout << "LocalFunction Friend Visit Room_" << building->Room_Bed << endl;
	cout << "LocalFunction Friend Visit Room_" << building->Room_Sitting << endl;
}
void goodgay1::visit1()
{
	//cout << "LocalFunction Friend Visit Room_" << building->Room_Bed << endl;
	cout << "LocalFunction Friend Visit Room_" << building->Room_Sitting << endl;
}


void F_FriendMain()
{
#pragma region 全局函数做友元示例
	F_Visit();
	F_Visit2();
#pragma endregion

#pragma region 类做友元示例
	GoodGay g;
	g.visit();
#pragma endregion

#pragma region 成员函数做友元示例(实现较为特殊，应多注意写法) 
	goodgay1 g1;
	g1.visit();
	g1.visit1();
#pragma endregion
}

void main_Friend()
{
	F_FriendMain();
}