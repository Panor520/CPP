#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

//谓词predicate
//谓词定义：返回类型是布尔类型仿函数的叫做谓词（predicate），其中有一个参数叫一元谓词，两个参数叫二元谓词
//

#pragma region 一元谓词

class testweiciclass_fo
{
public:
	bool operator()(int x)//谓词；返回值为bool类型
	{
		return x > 5;
	}
};

void test1weicifun_fo()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//算法中find_if方法的第三个参数就是一元谓词，以此来测试一元谓词的使用
	vector<int>::iterator it = find_if(v.begin(), v.end(), testweiciclass_fo());

	if (it == v.end())
	{
		cout << "未找到大于5的数" << endl;
	}
	else
	{
		cout << "找到大于5的数为：" << *it << endl;
	}
}
#pragma endregion

#pragma region 二元谓词
//sort算法第三个参数为二元谓词，以此来测试二元谓词的使用
class MyCompare_fo
{
public:
	bool operator()(int a,int b)
	{
		return a > b;
	}
};
void weiciprintvector(vector<int> &v)
{
	for (vector<int>::iterator i = v.begin(); i !=v.end() ; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test2weici_fo()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(30);

	sort(v.begin(),v.end());//sort排序算法 不指定谓词参数时默认为从小到大排序
	weiciprintvector(v);

	//利用自定义二元谓词 指定sort算法的排序规则
	sort(v.begin(),v.end(), MyCompare_fo());
	cout << "自定义算法排序后：" << endl;
	weiciprintvector(v);
}
#pragma endregion


void main_weici()
{
	//test1weicifun_fo();
	test2weici_fo();
}