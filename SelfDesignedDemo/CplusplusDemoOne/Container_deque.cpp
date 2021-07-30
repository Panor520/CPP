//deque
//双端数组，可以对头端和尾端进行插入删除操作
//与vector区别：
//vector头插删除效率低，数据量越大，效率越低
//deque相对而言对头部插入删除速度比vector快
//vector（连续的内存空间）访问元素速度比deque快
//deque的内部实现是中控器+缓冲区
//中控器控制中维护缓冲区地址
//缓冲区中存放数据

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printdeque(deque<int> &d)
{
	for (deque<int>::const_iterator i = d.begin(); i !=d.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//deque structure
void deque_structure()
{
	deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printdeque(d);

	//Structure method 1
	deque<int> d1(d.begin(),d.end());
	printdeque(d1);

	//structure method 2
	deque<int> d2(10,11);
	printdeque(d2);

	//structure method 3
	deque<int> d3(d2);
	printdeque(d3);
}

//deque assign
void deque_assign()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printdeque(d);

	deque<int> d1;
	d1 = d;
	printdeque(d);

	deque<int> d2;
	d2.assign(d.begin(),d.end());
	printdeque(d2);

	deque<int> d3;
	d3.assign(5,12);
	printdeque(d3);
}

//deque resize
void deque_resize()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printdeque(d);

	if (!d.empty())
	{
		cout << "unempty" << endl;
		cout << "" << d.size() << endl;
	}

	d.resize(7);//删除新长度之后的数据
	printdeque(d);

	d.resize(10);//后面新增的大小默认用0填充
	printdeque(d);

	d.resize(15,11);//后面新增的大小用指定数据11填充
	printdeque(d);

	d.resize(5,22);
	printdeque(d);
}

//deque insertdelete
void deque_insertdel()
{
	deque<int> d;
	for (int i = 5; i < 10; i++)
	{
		d.push_back(i);//尾插
	}
	printdeque(d);
	for (int i = 0; i < 5; i++)
	{
		d.push_front(i);//头插
	}
	printdeque(d);

	d.pop_back();//尾删
	printdeque(d);
	d.pop_front();//头删
	printdeque(d);

	//在指定位置(这个位置必须是迭代器)插入一个元素的拷贝，返回新数据的位置
	deque<int>::iterator x= d.insert(d.begin(),111);
	cout <<"add 111:" << *x << endl;
	printdeque(d);

	d.insert(d.end(),2,00);
	printdeque(d);

	deque<int> d1;
	////在指定位置(这个位置必须是迭代器)插入d.begin(),d.end()之间的数据，无返回值
	d1.insert(d1.begin(),d.begin(),d.end());
	printdeque(d1);

	//清空
	//d1.clear();
	d1.erase(d1.begin(),d1.end());//返回下一个数据位置
	printdeque(d1);

	deque<int>::iterator I =  d.erase(d.begin());//返回下一个数据位置
	cout<<"d erase index:" << *I << endl;
	printdeque(d);
}

//deque data存取
void deque_cunqu()
{
	deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	cout <<"get first elem:" << d.front() << endl;
	cout << "get last elem:" << d.back() << endl;
}

//deque sort
void deque_sort()
{
	deque<int> d;
	d.push_back(3);
	d.push_back(6);
	d.push_back(2);
	d.push_back(7);
	d.push_back(4);
	d.push_back(1);
	d.push_back(5);

	printdeque(d);
	sort(d.begin(),d.end());//默认从小到大
	printdeque(d);
}

void main_deque()
{
	//deque_structure();
	//deque_assign();
	//deque_resize();
	//deque_insertdel();
	//deque_cunqu();
	deque_sort();
}