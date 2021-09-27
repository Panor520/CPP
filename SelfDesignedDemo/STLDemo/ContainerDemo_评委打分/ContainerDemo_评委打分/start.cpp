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

//打分 并返回平均值
int dequefun(Person &p)
{
	deque<int> d;
	for (int i = 0; i < 5; i++)
	{
		/*	cout << "请第"<<i<<"个评委输入选手"<<p.Name<<"的分数："<<endl;
		int score;
		cin >> score;
		d.push_back(score);*/
		d.push_back(rand()%41+60);//rand()返回0~RAND_MAX（32767）的整数
	}
	sort(d.begin(),d.end());//从大到小

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
	cout << "开始评分：" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i].score = dequefun(v[i]);
		cout << v.at(i).Name << "的成绩为：" << v[i].score << endl;
		cout << "----------------------------" << endl;
	}
}

void main()
{
	//GetScore();
	cout << rand()%100 << endl;

	cout << rand() % 100 << endl;
	cout << rand() % 100 << endl;
	cout <<1 % 100 << endl;//一个数除以另一个数，要是比另一个数小的话，商为0，余数就是它自己
	cout<< 111111%100 <<endl;//%100 肯定是零到100之间
}

