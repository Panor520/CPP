//STL中list和vector是最常被使用的容器
//list
//STL的链表是双向的
//双向迭代器，但只可以向前向后一位
//链表优点：
//·采用动态存储分配，不会造成浪费和溢出
//·执行插入删除方便，修改指针即可，不需要移动大量元素
//缺点
//·额外空间（指针域）以及时间（遍历）耗费大

#include <list>
#include<string>
#include <iostream>
using namespace std;

void printlist(list<int> &l)
{
	for (list<int>::iterator i = l.begin(); i !=l.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//structure
void list_structure()
{
	list<int> l;
	for (int i = 0; i < 5; i++)
	{
		l.push_back(i);
	}
	for (int i = 5; i < 10; i++)
	{
		l.push_front(i);
	}
	printlist(l);

	list<int> l1(l);
	printlist(l1);

	list<int> l2(l1.begin(),l1.end());
	printlist(l2);

	list<int> l3(3,22);
	printlist(l3);
}

//assignment swap
void list_assignswap()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	printlist(l);

	list<int> l1;
	//将迭代器区间内的数据拷贝赋值给了l1
	l1.assign(l.begin(),l.end());
	printlist(l1);

	list<int> l2;
	//等号赋值
	l2 = l1;
	printlist(l2);

	list<int> l3;
	l3.assign(3,111);
	printlist(l3);

	list<int> l4;
	for (int i = 10; i > 0; i--)
	{
		l4.push_back(i);
	}
	printlist(l4);
	
	//元素互换
	l4.swap(l);
	printlist(l4);
	printlist(l);
}

//list size
void list_size()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	printlist(l);

	if (!l.empty())
	{
		cout << "Not empty" << endl;
		cout << "size" << l.size() << endl;

		l.resize(15);
		printlist(l);
		cout << "resize" << l.size() << endl;

		l.resize(17,111);
		printlist(l);
		cout << "resize" << l.size() << endl;

		l.resize(10);
		printlist(l);
		cout << "resize" << l.size() << endl;
	}
}

//list insert and delete
void list_insertdel()
{
	list<int> l;
	for (int i = 5; i < 10; i++)
	{
		l.push_back(i);
	}
	printlist(l);
	for (int i = 6; i >-1; i--)
	{
		l.push_front(i);
	}
	printlist(l);

	//delete last elem
	l.pop_back();
	printlist(l);

	//delete first elem
	l.pop_front();
	printlist(l);

	//在迭代器位置（l.begin()）插入如elem的拷贝,返回新数据的位置
	list<int>::iterator index= l.insert(l.begin(),22);
	cout << *index << endl;
	printlist(l);

	l.insert(l.begin(),3,444);
	printlist(l);

	list<int> l1;
	for (int i = 97; i < 99; i++)
	{
		l1.push_back(i);
	}
	//在迭代器位置 插入迭代器区间的数据
	l.insert(l.begin(),l1.begin(),l1.end());
	printlist(l);
	printlist(l1);
	l1.clear();//清空
	//l1.erase(l1.begin(),l1.end());//清除迭代器区间的数据

	//删除迭代器位置的数据，返回下一个元素的位置
	list<int>::iterator lindex=	l.erase(l.begin());
	cout << *lindex << endl;
	printlist(l);

	l.remove(5);//删除容器中所有和elem（5） 匹配的元素
	printlist(l);
}

//list 存取
void list_cunqu()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	//不支持随机访问[] at操作
	int front= l.front();//get first elem
	int back = l.back();//get last elem
	cout << front << endl;
	cout << back << endl;

	//双向迭代器 逐个访问
	list<int>::iterator itB = l.begin();
	itB++;
	cout << "itB:" << *itB << endl;
	list<int>::iterator itE = l.end();
	itE--;
	cout << "itE:" << *itE << endl;
}


bool mycompare(int v1,int v2)
{
	return v1 > v2;
}
//list reverse and sort
void list_reversesort()
{
	list<int> l;
	l.push_back(4);
	l.push_back(2);
	l.push_back(5);
	l.push_back(3);
	l.push_back(1);

	printlist(l);

	//list reverse反转
	l.reverse();
	printlist(l);

	//不支持随机访问的容器 是不能用algorithm中的排序的，需要使用容器内部自带的排序方法   
	l.sort();//默认 从小到大 升序
	printlist(l);

	l.sort(mycompare);//指定排序规则 从大到小
	printlist(l);
}


//sort demo
//按年龄升序，年龄相同按身高降序
//list中自定义数据类型要指定排序规则
class list_person;
void sort_demo();
bool sortrule(list_person& p1, list_person& p2);
class list_person
{
	friend void sort_demo();
	friend bool sortrule(list_person& p1, list_person& p2);
public:
	list_person(string name,int age,int height)
	{
		this->Name = name;
		this->Age = age;
		this->Height = height;
	}
private:
	string Name;
	int Age;
	int Height;

};
bool sortrule(list_person &p1,list_person &p2)
{
	if (p1.Age==p2.Age)
	{
		return p1.Height > p2.Height;
	}
	return p1.Age > p2.Age;
}
void sort_demo()
{
	list<list_person> l;

	list_person p1("Tom",18,1);
	list_person p2("Yom", 18, 2);
	list_person p3("Uom", 19, 1);
	list_person p4("Iom", 20, 2);
	list_person p5("Oom", 17, 1);
	list_person p6("Pom", 18, 3);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<list_person>::iterator i = l.begin(); i !=l.end(); i++)
	{
		cout << "name:" << (*i).Name << " age:" << (*i).Age << " height:" << (*i).Height << endl;
	}
	//after sort
	l.sort(sortrule);
	cout << "after sort:" << endl;
	for (list<list_person>::iterator i = l.begin(); i != l.end(); i++)
	{
		cout << "name:" << (*i).Name << " age:" << (*i).Age << " height:" << (*i).Height << endl;
	}
}
void main_list()
{
	//list_structure();
	//list_assignswap();
	//list_size();
	//list_insertdel();
	//list_cunqu();
	//list_reversesort();

	sort_demo();
}