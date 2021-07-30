//map容器中所有元素都是pair
//pair第一个元素为key值，起到索引作用，第二个元素为value（实值）
//所有的元素都会根据元素的键值自动排序
//map/multimap属于关联式容器，底层结构是二叉树
//优点：可以根据key值快速找到value值
//map不允许重复key
//multimap允许重复key

#include <string>
#include <map>
#include <iostream>
using namespace std;

void print_map( map<int,string> &m)
{
	for (map<int,string>::iterator i = m.begin(); i !=m.end(); i++)
	{
		cout << "key=" << i->first << " value=" << i->second << endl;
	}
}

//structure
void map_structure()
{
	//create container map
	map<int, string> m;//插入的数据自动按key值排序

	m.insert(pair<int,string>(1,"aa"));
	m.insert(pair<int, string>(2, "bb"));
	m.insert(pair<int, string>(4, "dd"));
	m.insert(pair<int, string>(3, "cc"));
	cout<<"m:" << endl;
	print_map(m);

	map<int, string> m2(m);
	cout<<"m2:"<< endl;
print_map(m2);

map<int, string>m3;
m3 = m2;
cout << "m3:" << endl;
print_map(m3);
}

//size and swap
void map_sizeAndswap()
{
	map<int, string> m;
	m.insert(pair<int, string>(2, "bb"));
	m.insert(pair<int, string>(4, "dd"));
	m.insert(pair<int, string>(3, "cc"));
	m.insert(pair<int, string>(1, "aa"));

	if (!m.empty())
	{
		cout << "not empty" << endl;
		cout << "size:" << m.size() << endl;
		print_map(m);
	}

	map<int, string> m2;
	m2.insert(pair<int, string>(5, "ee"));
	m2.insert(pair<int, string>(6, "ff"));
	cout << "m2:" << endl;
	print_map(m2);
	cout << "after swap：" << endl;
	m2.swap(m);
	cout << "m:" << endl;
	print_map(m);

	cout << "m2:" << endl;
	print_map(m2);
}

//insert and delete
void map_insertandelete()
{
	map<int, string> m;
	//insert method 1
	m.insert(pair<int, string>(1, "aa"));
	//insert method 2
	m.insert(make_pair(3, "cc"));
	//insert method 3
	m.insert(map<int, string>::value_type(2, "bb"));
	//insert method 4
	m[4] = "dd";
	//输出时，如果没有该位置的数据，会默认空，并输出
	cout << m[6] << endl;
	//正确用法是输出key值对应的value，下面的例子就是输出bb
	cout << m[2] << endl;
	print_map(m);

	map<int, string> m2;
	m2 = m;

	map<int, string>::iterator it = m.erase(m.begin());//删除迭代器所在位置的数据，返回下一个元素的迭代器
	cout << "erase first elem:" << endl;
	print_map(m);
	cout << "next iterator:" << (*it).first << " " << (*it).second << endl;

	m.erase(3);//删除容器中的key值
	print_map(m);

	m.clear();
	if (!m.empty())
	{
		cout << "m empty" << endl;
	}

	m2.erase(m2.begin(), m2.end());
	if (m2.empty())
	{
		cout << "m2 empty" << endl;
	}
}

//find and cout
void map_findcount()
{
	map<int, string> m;
	m.insert(make_pair(2, "bb"));
	m.insert(make_pair(4, "dd"));
	m.insert(make_pair(3, "cc"));

	//find 获得key值所在的迭代器 ，若不存在则返回m.end()
	map<int, string>::iterator it = m.find(3);
	if (it != m.end())
	{
		cout << "exist key=3" << "; value=" << (*it).second << endl;
		cout << "cout(key=3):" << m.count(3) << endl;
	}
	cout << endl;
}

//sort

class map_compareOne
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;//
	}
};
void map_sort()
{
	map<int, string, map_compareOne> m;
	m.insert(make_pair(2,"bb"));
	m.insert(make_pair(4,"dd"));
	m.insert(make_pair(1, "aa"));
	m.insert(make_pair(3, "cc"));

	for (map<int,string,map_compareOne>::iterator i = m.begin(); i !=m.end(); i++)
	{
		cout<<"key:"<<(*i).first << " value:" << (*i).second << endl;
	}
}

void main()
{
	//map_structure();
	//map_sizeAndswap();
	//map_insertandelete();
	//map_insertandelete();
	//map_findcount();
	map_sort();
}