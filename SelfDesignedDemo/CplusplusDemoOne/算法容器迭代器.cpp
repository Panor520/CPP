//容器：置物之所也
//STL容器就是将运用最广泛的一些数据结构实现出来
//常用的数据结构：数组、链表、树、栈、队列、集合、映射表等
//容器分为序列式容器和关联式容器：
//序列式容器：强调值的排序，序列式容器中的每个元素都有固定的位置
// 例：一个数组为{1,3,5,4,2}到容器里还是{1,3,5,4,2}
//关联式容器（会进行排序）：二叉树结构，各元素之间没有严格的物理上的顺序关系
// 例：一个数组为{1,3,5,4,2}到容器里就变为了{1,2,3,4,5}

//算法（Algorithms）：问题之解法也
//有限的步骤解决逻辑或数学上的问题
//算法分为质变算法和非质变算法
//质变算法：指运算过程中会更改区间内的元素内容。例如拷贝、替换、删除等。
//非质变算法：指运算过程中不会更改区间内的元素内容。例如查找、计数、遍历、寻找极值等。

//
//算法通过容器中的迭代器才能访问容器中的元素

//每个容器都有自己专属的迭代器
//迭代器类似于指针，初学者可以先理解迭代器为指针
//---------------------------------------------------------------------------------------------------------------------
//-	种类			  -  	    功能												-			支持运算							 -		
//-输入迭代器	  -  对数据的只读访问											-	只读，支持++、==、！=					  	 -
//-输出迭代器	  -  对数据的只写访问											-	只写，支持++								 -
//-前项迭代器	  -  读写操作，并能向前推进迭代器								-	读写，支持++、==、！+					  	 -
//-双向迭代器	  -  读写操作，并能向前向后推进迭代器							-	读写，支持++、--						     -
//-随机访问迭代器	  -  读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器		-	读写，支持++、--、[n]、-n、<、<=、>、>=	 - 
//---------------------------------------------------------------------------------------------------------------------
//常用的是双向和随机访问迭代器



//下面是一个实例
//Vector 可以理解为数组 容器在使用时都要包含头文件
//插入、遍历容器
#include <vector>
#include <algorithm>//标准算法头文件
#include <iostream>
#include <string>
using namespace std;

class vector_Person;
void vector_printPer(vector_Person& v);
void vector_printPer1(vector_Person* v);

class vector_Person
{
	friend void vector_printPer(vector_Person& v);
	friend void vector_printPer1(vector_Person* v);
	friend void vector_test03();
public:
	vector_Person(string name,int age)
	{
		this->Name = name;
		this->Age = age;
	}
private:
	string Name;
	int Age;
};

void vector_print(int x)
{
	cout<<x <<endl;
}

void vector_test01()
{
	vector<int> v;
	//尾插法
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//遍历方法一
	vector<int>::iterator itBegin = v.begin();//容器vector第一个元素的未知
	vector<int>::iterator itEnd = v.end(); //容器vector最后
	while (itBegin!=itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//遍历方法二
	for (vector<int>::iterator  it = v.begin(); it!=v.end(); it++)//iterator 迭代器
	{
		//cout<<&it << endl;
		cout<<*it<<endl;
	}

	//遍历方法三 利用STL提供的方法
	for_each(v.begin(), v.end(), vector_print);//转到定义查看该方法详细逻辑

}

void vector_printPer(vector_Person &v)
{
	cout << v.Name << " " << v.Age << endl;
}

void vector_printPer1(vector_Person * v)
{
	cout << (*v).Name << " " << (*v).Age << endl;
}

//容器中存放自定义类型
void vector_test02()
{
	vector<vector_Person> v;
	vector_Person va("Tom",10);
	vector_Person va1("Tom1", 11);
	vector_Person va2("Tom2", 12);
	v.push_back(va);
	v.push_back(va1);
	v.push_back(va2);

	for_each(v.begin(),v.end(), vector_printPer);
}

//容器中存放自定义类型指针
void vector_test03()
{
	vector<vector_Person*> v;
	vector_Person va("Tom", 10);
	vector_Person va1("Tom1", 11);
	vector_Person va2("Tom2", 12);
	v.push_back(&va);
	v.push_back(&va1);
	v.push_back(&va2);

	for_each(v.begin(), v.end(), vector_printPer1);
	for (vector<vector_Person*>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (*i)->Name<< " " << (*i)->Age << endl;
	}
}


void vector_printVV(vector<int> & v)
{
	for_each(v.begin(),v.end(), vector_print);
	cout << endl;
}

void vector_test04()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<vector<int>> vv;
	v1.push_back(1);
	v1.push_back(11);
	v1.push_back(111);
	v2.push_back(2);
	v2.push_back(22);
	v2.push_back(222);
	v3.push_back(3);
	v3.push_back(33);
	v3.push_back(333);
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);

	for (vector<vector<int>>::iterator i =vv.begin() ; i != vv.end(); i++)
	{
		/*vector<int> v = *i;
		for (vector<int>::iterator j = v.begin(); j != v.end(); j++)*/
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << (*j) << " ";
		}
		cout << endl;
	}
	cout << "for_each：" << endl;
	for_each(vv.begin(), vv.end(), vector_printVV);
}

void main_AlgorithmContainerIterator()
{
	/*vector_test01();
	vector_test02();
	vector_test03();*/
	vector_test04();
}