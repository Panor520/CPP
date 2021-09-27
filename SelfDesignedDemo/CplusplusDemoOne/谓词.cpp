#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

//ν��predicate
//ν�ʶ��壺���������ǲ������ͷº����Ľ���ν�ʣ�predicate����������һ��������һԪν�ʣ����������ж�Ԫν��
//

#pragma region һԪν��

class testweiciclass_fo
{
public:
	bool operator()(int x)//ν�ʣ�����ֵΪbool����
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

	//�㷨��find_if�����ĵ�������������һԪν�ʣ��Դ�������һԪν�ʵ�ʹ��
	vector<int>::iterator it = find_if(v.begin(), v.end(), testweiciclass_fo());

	if (it == v.end())
	{
		cout << "δ�ҵ�����5����" << endl;
	}
	else
	{
		cout << "�ҵ�����5����Ϊ��" << *it << endl;
	}
}
#pragma endregion

#pragma region ��Ԫν��
//sort�㷨����������Ϊ��Ԫν�ʣ��Դ������Զ�Ԫν�ʵ�ʹ��
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

	sort(v.begin(),v.end());//sort�����㷨 ��ָ��ν�ʲ���ʱĬ��Ϊ��С��������
	weiciprintvector(v);

	//�����Զ����Ԫν�� ָ��sort�㷨���������
	sort(v.begin(),v.end(), MyCompare_fo());
	cout << "�Զ����㷨�����" << endl;
	weiciprintvector(v);
}
#pragma endregion


void main_weici()
{
	//test1weicifun_fo();
	test2weici_fo();
}