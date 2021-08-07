#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#pragma region for_each
//便利算法foreach
void foreach_print(int a)
{
	cout << a << " ";
}

class foreach_fo
{
public:
	void operator()(int x)
	{
		cout << x << " ";
	}
};

void test_foreach()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(),v.end(), foreach_print);//use Mycustom function print vector element 
	cout << endl;

	for_each(v.begin(), v.end(), foreach_fo());
	cout << endl;
}

#pragma endregion

#pragma region transform

class Mycustom_transform
{
public:
	int operator()(int x)
	{
		return x;
	}
};

//use transform copy element to other container 
void test_transform()
{
	vector<int> v;
	for (int  i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vTarget;
	vTarget.resize(v.size());

	transform(v.begin(),v.end(),vTarget.begin(), Mycustom_transform());

	for_each(vTarget.begin(),vTarget.end(), foreach_print);
	cout << endl;

}
#pragma endregion

#pragma region find algorithm

class test_findPerson
{
	friend void test_find2();
public:
	test_findPerson(string name,int age)
	{
		this->Name = name;
		this->Age = age;
	}
	bool operator==(const test_findPerson &p) //use find custom datatype must overload operator==,else find be error
	{
		if (this->Name==p.Name&&this->Age==p.Age)
		{
			return true;
		}
		return false;
	}

	string Name;
	int Age;
};

void test_find()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it= find(v.begin(),v.end(),10);//find:if find element will return the element iterator,else will return end iterator
	if (it!=v.end())
	{
		cout << "find element:" << *it << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
}

void test_find2()
{
	vector<test_findPerson> v;
	test_findPerson p1("aa",10);
	test_findPerson p2("bb", 20);
	test_findPerson p3("cc", 30);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	vector<test_findPerson>::iterator it=  find(v.begin(),v.end(),p2);//use find custom datatype must overload operator==
	if (it!=v.end())
	{
		cout << "find element:" << (*it).Name << " " << (*it).Age << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
}
#pragma endregion

#pragma region find_if
//查找区间里是否有满足条件的元素，有的话返回迭代器位置
class test_find_if_pre
{
public:
	bool operator()(const test_findPerson &p)
	{
		return p.Age > 20;
	}
};

void test_find_if()
{
	test_findPerson P1("AA", 10);
	test_findPerson P2("BB", 20);
	test_findPerson P3("CC", 30);

	vector<test_findPerson> v;
	v.push_back(P1);
	v.push_back(P2);
	v.push_back(P3);

	vector<test_findPerson>::iterator it = find_if(v.begin(),v.end(), test_find_if_pre());//find_if third parameter is a function object
	if (it!=v.end())
	{
		cout<<" find element:"<<(*it).Name << " "<<(*it).Age << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
}

#pragma endregion

#pragma region Adjacent_find
//迭代器区间内是否有相邻重复的元素，返回第一个元素迭代器位置，否则返回end()迭代器位置
void test_adjacent_find()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	vector<int>::iterator it=  adjacent_find(v.begin(),v.end());
	if (it!=v.end())
	{
		cout <<"find element:" << *it << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
	
}
#pragma endregion


void main()
{
	//test_foreach();
	//test_transform();
	/*test_find();
	test_find2();*/
	//test_find_if();
	test_adjacent_find();
}