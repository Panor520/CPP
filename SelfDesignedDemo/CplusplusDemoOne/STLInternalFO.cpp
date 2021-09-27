#include <iostream>
#include <functional>//Use STL internal function object need this headfile
using namespace std;
#include <vector>
#include <algorithm>

//���齲��STL�ڽ���������
// 
#pragma region STL Internal function object negate


//My custome negate
class Mynegate_fo
{
public:
	int operator()(int x)
	{
		return -x;
	}
};


//STL Internal Function Object negate
void test01_STLInternal()
{
	negate<int> n;
	cout << n(100) << endl;//out put negate number 100

	Mynegate_fo m;
	cout << m(10) << endl;//use Mycustome  out put negate number 100
}

#pragma endregion

#pragma region STL Internal function object plus



class Myplus_fo
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};

//STL Internal function object plus;Two element predicate
void test02_STLIntenal()
{
	plus<int> p;
	cout <<p(10,20) <<endl;

	Myplus_fo m;
	cout<< m(20,20) <<endl;
}
#pragma endregion

#pragma region  STL Internal function object ��ϵ�º���

void test03_STLInternal()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);

	sort(v.begin(),v.end(),less<int>());//default less function object

	for (vector<int>::iterator i = v.begin(); i !=v.end() ; i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	sort(v.begin(),v.end(),greater<int>());//greater is STLInternal function object,And sort algorithm the third parameter default less fo instead of greater fo

	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

#pragma endregion

#pragma region STL Internal function object �߼��º���

//Mycustom
class MyCustom_Logical_not
{
public:
	bool operator()(bool b)
	{
		return !b;
	}
};

//���߼���Ϊ��
void test04_STLInternal()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);

	for (vector<bool>::iterator i = v1.begin(); i !=v1.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	vector<bool> v2;
	v2.resize(v1.size());

	transform(v1.begin(),v1.end(),v2.begin(),logical_not<bool>());//use algorithm transform test logical_not function object

	for (vector<bool>::iterator i = v2.begin(); i != v2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

//use MyCustom function object ʵ��Ч��������ʹ��STL�ڽ����������Ч��һ��
	vector<bool> v3;
	v3.resize(v2.size());

	transform(v1.begin(),v1.end(),v3.begin(), MyCustom_Logical_not());

	for (vector<bool>::iterator i = v2.begin(); i != v2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
#pragma endregion


void main_FOInternal()//_FOInternal
{
	/*test01_STLInternal();
	test02_STLIntenal();*/
	//test03_STLInternal();
	test04_STLInternal();
}