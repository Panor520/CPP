//map����������Ԫ�ض���pair
//pair��һ��Ԫ��Ϊkeyֵ�����������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
//���е�Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
//map/multimap���ڹ���ʽ�������ײ�ṹ�Ƕ�����
//�ŵ㣺���Ը���keyֵ�����ҵ�valueֵ
//map�������ظ�key
//multimap�����ظ�key

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
	map<int, string> m;//����������Զ���keyֵ����

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
	cout << "after swap��" << endl;
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
	//���ʱ�����û�и�λ�õ����ݣ���Ĭ�Ͽգ������
	cout << m[6] << endl;
	//��ȷ�÷������keyֵ��Ӧ��value����������Ӿ������bb
	cout << m[2] << endl;
	print_map(m);

	map<int, string> m2;
	m2 = m;

	map<int, string>::iterator it = m.erase(m.begin());//ɾ������������λ�õ����ݣ�������һ��Ԫ�صĵ�����
	cout << "erase first elem:" << endl;
	print_map(m);
	cout << "next iterator:" << (*it).first << " " << (*it).second << endl;

	m.erase(3);//ɾ�������е�keyֵ
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

	//find ���keyֵ���ڵĵ����� �����������򷵻�m.end()
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