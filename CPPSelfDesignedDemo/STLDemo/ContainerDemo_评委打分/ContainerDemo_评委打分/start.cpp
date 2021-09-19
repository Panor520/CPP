#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Person;
int dequefun(Person& p);
void GetScore();
class Person
{
	friend int dequefun(Person& p);
	friend void GetScore();
public:
	Person(string name,int age)
	{
		this->Name = name;
		this->Age = age;
	}
private:
	string Name;
	int Age;
	int score;
};

//��� ������ƽ��ֵ
int dequefun(Person &p)
{
	deque<int> d;
	for (int i = 0; i < 5; i++)
	{
		/*	cout << "���"<<i<<"����ί����ѡ��"<<p.Name<<"�ķ�����"<<endl;
		int score;
		cin >> score;
		d.push_back(score);*/
		d.push_back(rand()%41+60);//rand()����0~RAND_MAX��32767��������
	}
	sort(d.begin(),d.end());//�Ӵ�С

	d.pop_back();//erase top score
	d.pop_front();//erase low score 

	int sum=0;
	for (int i = 0; i < 3; i++)
	{
		sum += d[i];
	}

	return sum/3;
}

vector<Person> createPlayer()
{
	vector<Person> vec;
	Person p1("Tom", 18);
	Person p2("Lip", 18);

	vec.push_back(p1);
	vec.push_back(p2);

	return vec;
}

void GetScore()
{
	vector<Person> v;
	v = createPlayer();
	cout << "��ʼ���֣�" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i].score = dequefun(v[i]);
		cout << v.at(i).Name << "�ĳɼ�Ϊ��" << v[i].score << endl;
		cout << "----------------------------" << endl;
	}
}

void main()
{
	//GetScore();
	cout << rand()%100 << endl;

	cout << rand() % 100 << endl;
	cout << rand() % 100 << endl;
	cout <<1 % 100 << endl;//һ����������һ������Ҫ�Ǳ���һ����С�Ļ�����Ϊ0�������������Լ�
	cout<< 111111%100 <<endl;//%100 �϶����㵽100֮��
}

