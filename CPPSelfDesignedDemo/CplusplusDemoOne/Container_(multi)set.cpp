//(multi)set
//���ڹ���ʽ�������ײ�ṹ�Ƕ�����ʵ�ֵ�
//����Ԫ�ض��ڲ���ʱ�Զ�������
//set �в��������ظ���Ԫ��
//multiset�������ظ�Ԫ��

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

//���췽ʽ
void set_structure()
{
	set<int> s;
	s.insert(1);//set��������ֻ��insert��ʽ
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

	//���롢
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	printset(s);
	//ɾ����������ָ��Ԫ�أ�������һ��Ԫ��λ��
	set<int>::iterator index= s.erase(s.begin());
	cout << "index:" << *index << endl;
	printset(s);

	//ɾ������������Ԫ�أ�������һ��Ԫ��λ��
	//set<int>::iterator index1 = s.erase(s.begin(),s.end());

	//�������
	//s.clear();
	//cout<< "index1:" << *index << endl;
	//printset(s);

	//ɾ��������ֵΪ3��Ԫ��
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

	//����Ԫ�أ����ظ�Ԫ�ص�����
	set<int>::iterator it= s.find(2);
	cout<<"find(2):"<<*it << endl;

	//ͳ��Ԫ�ظ���
	int x = s.count(2);
	cout << "count:" <<s.count(2) <<endl;
}

//set and multiset
//set�����з���ֵ��multiset�����޷���ֵ
void set_multiset()
{
	set<int> s;
	//�����Ƿ����ɹ���ʶ
	pair<set<int>::iterator, bool> p = s.insert(2);
	if (p.second)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
	//set���ܲ����ظ����ݣ��ʵڶ��β���ʧ��
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
class MyCompare//�º�����һ�����ͣ�ָ��дС����
{
public:
	bool operator()(int v1, int v2) const //����ط�����const�����º���ʹ��ʱ�ᱨ��
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

	printset(s);//Ĭ�������С����

	//ָ���������Ϊ�Ӵ�С
	//���÷º���
	set<int,MyCompare> s1;//���÷º���ָ��set��������
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
		return s1.Age > s2.Age;//> ���� ,<����
	}
};
void set_sortTwo()
{
	//�Զ����������� ����ָ���������
	set<set_person, set_Comparetwo> s;

	set_person p1("����",18);
	set_person p2("����", 20);
	set_person p3("�ŷ�", 19);
	set_person p4("����", 17);

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