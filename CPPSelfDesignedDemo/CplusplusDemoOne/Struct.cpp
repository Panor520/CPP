#include <iostream>
#include <string>
using namespace std;

//struct 默认权限是Public Class默认权限是Private
struct  Student
{
	string name;
	int score;
};

struct  Teacher
{
	int ID;
	string Name;
	Student students[5];
};

void FillTeacher(struct Teacher *struc,int len)
{
	string namel = "abcde";
	for (int i = 0; i < len; i++)
	{
		(struc+i)->ID = i+1;
		(struc + i)->Name = "TeacherName";
		(struc + i)->Name += namel[i];

		struct Student s[5];
		for (int j = 0; j < 5; j++)
		{
			((struc + i)->students + j)->name = "StudentName";
			((struc + i)->students + j)->name += namel[j];
			((struc + i)->students + j)->score = 90 + j;
		}
	}
}

void ShowData(Teacher *t,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "Teacher" << i+1 << ":" << "ID " << (t + i)->ID << " Name " << (t + i)->Name<<endl;
		for (int j= 0; j < 5; j++)
		{
			cout << "  Student" << j+1 << ":Name " << ((t + i)->students + j)->name << " Score " << ((t + i)->students + j)->score << endl;;
		}
		cout << endl << endl;
	}
}

void structOne()
{
	Teacher te[3];
	int len = sizeof(te) / sizeof(*te);
	FillTeacher(te, len);
	ShowData(te, len);
}


struct Hero
{
	string name;
	int age;
	string gender;
};

void BubbleSort2(Hero *hero,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j=0; j < len - 1 - i; j++)
		{
			/*if (*(arr+j)>*(arr+j+1))
			{
				int temp =*( arr + j);
				*(arr + j) = *(arr+j+1);
				*(arr + j + 1) = temp;
			}*/

			if ((hero + j)->age > (hero + j + 1)->age)
			{
				Hero temp = *(hero + j);
				*(hero + j) = *(hero + j + 1);
				*(hero + j + 1) = temp;
			}

		}
	}
}

void structtwo()
{
	Hero hero[5] = {
		{"貂蝉",18,"女"},
		{"西施",17,"女"},
		{"吕布",19,"男"},
		{"关羽",22,"男"},
		{"张飞",15,"男"}
	};
	int len = sizeof(hero) / sizeof(hero[0]);

	for (int i = 0; i < len; i++)
	{
		cout << "Name:" << (hero + i)->name<<" Age:"<<(hero+i)->age<<" gender:"<<(hero+i)->gender << endl;
	}
	BubbleSort2(hero,len);
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "Name:" << (hero + i)->name << " Age:" << (hero + i)->age << " gender:" << (hero + i)->gender << endl;
	}
}


void mainste()
{
	//structOne();
	structtwo();
}