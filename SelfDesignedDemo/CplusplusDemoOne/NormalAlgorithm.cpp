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

#pragma region binary_search
//二分查找算法 容器必须是有序的(如果是无序的容器返回结果就未知是否正确),返回值是bool类型
void binary_search()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool result = binary_search(v.begin(),v.end(),30);
	if (result)
	{
		cout << "find element" << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
}
#pragma endregion

#pragma region count
//统计元素出现次数

void test_count()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	int result = count(v.begin(),v.end(),4);
	cout << "该元素出现次数为：" << result << endl;
}

//统计自定义类型
class count_Per
{
public:
	count_Per(string name, int age)
	{
		this->Name = name;
		this->Age = age;
	}
	bool operator==(const count_Per &p)//根据年龄是否相同统计
	{
		if (this->Age==p.Age)
		{
			return true;
		}
		return false;
	}
	string Name;
	int Age;
};
void test_count1()
{
	vector<count_Per> v;
	count_Per p1("aa",10);
	count_Per p2("bb", 12);
	count_Per p3("cc", 11);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	
	count_Per pp("dd", 12);

	int result= count(v.begin(),v.end(), pp);//根据年龄是否相同统计,count底层实现需要操作符==比较相同元素，故自定义类型需要重载操作符==让编译器知道怎么判断两元素相等
	if (result>0)
	{
		cout << "find element" << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
	
}
#pragma endregion

#pragma region count_if
//按条件统计元素出现次数
class test_countif_predicate
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};

void test_count_if()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	int num=count_if(v.begin(),v.end(), test_countif_predicate());//count_if 返回符合条件的元素个数
	if (num>0)
	{
		cout << "find element" << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
}
class test_countif_predicate1
{
public:
	test_countif_predicate1(string name,int age)
	{
		this->Age = age;
		this->Name = name;
	}
	
	int Age;
	string Name;
};
class test_pre_countif
{
public:
	bool operator()(const test_countif_predicate1& c)
	{
		return c.Age > 20;
	}
};
void test_count_if1()
{
	vector<test_countif_predicate1> v;
	test_countif_predicate1 p1("aa",10);
	test_countif_predicate1 p2("bb", 20);
	test_countif_predicate1 p3("cc", 30);
	test_countif_predicate1 p4("dd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	int num = count_if(v.begin(),v.end(), test_pre_countif());

	if (num > 0)
	{
		cout << "find element:"<<num << endl;
	}
	else
	{
		cout << "can't find element" << endl;
	}
}
#pragma endregion

#pragma region sort
//默认为升序，可通过谓词设置为降序
class test_sortC
{
public:
	test_sortC(string name,int age)
	{
		this->Name = name;
		this->Age = age;
	}
	string Name;
	int Age;
};
class test_sortC_pre
{
public:
	bool operator()( test_sortC &c1, test_sortC& c2)
	{
		if (c1.Age>c2.Age)
		{
			return true;
		}
		return false;
	}
};

void test_print_sort(test_sortC &c)
{
	cout << c.Name<<" " << c.Age << endl;
}
void test_sort()
{
	vector<test_sortC> v;

	test_sortC t1("a",10);
	test_sortC t2("d", 40);
	test_sortC t3("b", 20);
	test_sortC t4("c", 30);

	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	v.push_back(t4);

	sort(v.begin(),v.end(), test_sortC_pre());//自定义排序规则谓词:test_sortC_pre

	for_each(v.begin(),v.end(), test_print_sort);//自定义循方法test_print_sort
}


void test_sort_print1(int x)
{
	cout << x << endl;
}
void test_sort1()
{
	vector<int> v;
	 
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);

	sort(v.begin(),v.end(),greater<int>());//默认 less 升序

	for_each(v.begin(),v.end(), test_sort_print1);
}
#pragma endregion

#pragma region random_shuffle
//随机打乱序列
void test_random_shuffle()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(),v.end(), test_sort_print1);
	srand((unsigned int)time(NULL));//根据时间随机打乱
	random_shuffle(v.begin(),v.end());
	cout << "--------------------" << endl;
	for_each(v.begin(), v.end(), test_sort_print1);

}
#pragma endregion

#pragma region Merge
//将两个容器中的数据合并到另一个容器中
//要合并的两个容器必须是有序的。
void test_merge()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);

	vector<int> v;
	v.resize(v1.size()+v2.size());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());//目标容器必须有大小

	for_each(v.begin(),v.end(),test_sort_print1);
}
#pragma endregion

#pragma region Reverse
//将容器中的元素倒置
void test_reverse()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	for_each(v.begin(),v.end(),test_sort_print1);
	reverse(v.begin(),v.end());
	cout << "after reverse" << endl;
	for_each(v.begin(), v.end(), test_sort_print1);
}
#pragma endregion

#pragma region copy
//将一个容器中的诗句拷贝到另一个容器中
void test_copy()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());

	for_each(v2.begin(),v2.end(),test_sort_print1);
}
#pragma endregion

#pragma region replace
//将迭代器区间内的元素替换为新的元素
void test_replace()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for_each(v.begin(),v.end(),test_sort_print1);
	cout << "after replace" << endl;
	replace(v.begin(),v.end(),1,1000);
	for_each(v.begin(), v.end(), test_sort_print1);
}
#pragma endregion

#pragma region replace_if
//替换符合条件的元素
class test_replace_if_pre
{
public:
	bool operator()(int x)
	{
		if (x>2)
		{
			return true;
		}
		return false;
	}
};
void test_replace_if()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for_each(v.begin(),v.end(),test_sort_print1);
	replace_if(v.begin(),v.end(), test_replace_if_pre(),300);
	cout << "after replace_if-----------------" << endl;
	for_each(v.begin(), v.end(), test_sort_print1);
}
#pragma endregion



void main()
{
	
	//test_foreach();
	//test_transform();
	//test_find();
	//test_find2();
	//test_find_if();
	//test_adjacent_find();
	//binary_search();
	//test_count();
	//test_count1();
	//test_count_if();
	//test_count_if1();
	//test_sort();
	//test_sort1();
	//test_random_shuffle();
	//test_merge();
	//test_reverse();
	//test_copy();
	//test_replace();
	test_replace_if();
}