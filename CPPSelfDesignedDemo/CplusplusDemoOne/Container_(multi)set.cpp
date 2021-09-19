//(multi)set
//属于关联式容器，底层结构是二叉树实现的
//所有元素都在插入时自动被排序
//set 中不允许有重复的元素
//multiset可以有重复元素

#include <set>
#include <iostream>
#include <string>
using namespace std;


void printset(set<int> &s)
{
	for (set<int>::iterator i = s.begin(); i !=s.end(); i++)
	{
		cout<<(*i) <<" ";
	}
	cout << endl;
}

//构造方式
void set_structure()
{
	set<int> s;
	s.insert(1);//set插入数据只有insert方式
	s.insert(3);
	s.insert(2);
	s.insert(4);
	printset(s);

	set<int> s1(s);
	printset(s1);

	set<int> s2;
	s2 = s1;
	printset(s2);
}

//size and swap
void set_sizeswap()
{
	set<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.insert(i);
	}
	printset(s);

	if (!s.empty())
	{
		cout << "not empty" << endl;
		cout << "size:" << s.size() << endl;
	}

	set<int> s1;
	for (int i = 90; i < 95; i++)
	{
		s1.insert(i);
	}
	printset(s1);

	s1.swap(s);
	printset(s1);
	printset(s);
}

//insert and delete
void set_insertdele()
{
	set<int> s;

	//插入、
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	printset(s);
	//删除迭代器所指的元素，返回下一个元素位置
	set<int>::iterator index= s.erase(s.begin());
	cout << "index:" << *index << endl;
	printset(s);

	//删除迭代器区间元素，返回下一个元素位置
	//set<int>::iterator index1 = s.erase(s.begin(),s.end());

	//清空容器
	//s.clear();
	//cout<< "index1:" << *index << endl;
	//printset(s);

	//删除容器中值为3的元素
	s.erase(3);
	printset(s);
}

//find and count
void set_findcount()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);

	//查找元素，返回该元素迭代器
	set<int>::iterator it= s.find(2);
	cout<<"find(2):"<<*it << endl;

	//统计元素个数
	int x = s.count(2);
	cout << "count:" <<s.count(2) <<endl;
}

//set and multiset
//set插入有返回值，multiset插入无返回值
void set_multiset()
{
	set<int> s;
	//接收是否插入成功标识
	pair<set<int>::iterator, bool> p = s.insert(2);
	if (p.second)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
	//set不能插入重复数据，故第二次插入失败
	p = s.insert(2);
	if (p.second)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}

}

//pair structure
void set_pair()
{
	pair<string, int> p("tom",19);
	cout << p.first << " " << p.second << endl;

	pair<string, int> p1 = make_pair("am",40);
	cout << p1.first << " " << p1.second << endl;
}

//set sort
class MyCompare//仿函数是一个类型，指重写小括号
{
public:
	bool operator()(int v1, int v2) const //这个地方不加const在做仿函数使用时会报错
	{
		return v1 > v2;//v1>v2 true,else false
	}
};
void set_sortOne()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(4);
	s.insert(3);

	printset(s);//默认排序从小到大

	//指定排序规则为从大到小
	//利用仿函数
	set<int,MyCompare> s1;//利用仿函数指定set容器规则
	s1.insert(1);
	s1.insert(2);
	s1.insert(4);
	s1.insert(3);

	for (set<int, MyCompare>::iterator i = s1.begin(); i != s1.end(); i++)
	{
		cout << *i << " ";
	}
	cout<< endl;
}


class set_person
{
public:
	set_person(string  name,int age)
	{
		this->Name = name;
		this->Age = age;
	}
	string Name;
	int Age;
};
class set_Comparetwo
{
public:
	bool operator()(const set_person& s1, const set_person& s2) const
	{
		return s1.Age > s2.Age;//> 降序 ,<升序
	}
};
void set_sortTwo()
{
	//自定义数据类型 都会指定排序规则
	set<set_person, set_Comparetwo> s;

	set_person p1("刘备",18);
	set_person p2("关羽", 20);
	set_person p3("张飞", 19);
	set_person p4("赵云", 17);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<set_person, set_Comparetwo>::iterator i = s.begin(); i!=s.end(); i++)
	{
		cout << "name:" << i->Name << " " << "age:" << i->Age << endl;
	}
}

void main_set()
{
	//set_structure();
	//set_sizeswap();
	//set_insertdele();
	//set_findcount();
	//set_multiset();
	//set_pair(); 
	//set_sortOne();
	set_sortTwo();
}