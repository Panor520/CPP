#include <iostream>
#include <string>
using namespace std;

#pragma region �ٺ͢�
//����Ģٺ͢�Ҫ��ȫ�ֺ�������ʵ��ǰʵ��
//��
template <typename T1, typename T2>
class ClassTemplateFriend;
//��
template <typename T1, typename T2>
void PrintPerson2(ClassTemplateFriend<T1, T2> p)
{
	cout << p.Name << " " << p.Age << endl;
}
#pragma endregion


template <typename T1,typename T2>
class ClassTemplateFriend
{
	//ȫ�ֺ��� ����ʵ��
	friend void PrintPerson(ClassTemplateFriend<T1,T2> p)
	{
		cout << p.Name << " " << p.Age << endl;
	}
	//ȫ�ֺ��� ����ʵ��
	//1.�ӿ�ģ������б� ����
	//2.���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ��� ������벻��ȥ ��ٺ͢�
	friend void PrintPerson2<>(ClassTemplateFriend<T1, T2> p);
public:
	ClassTemplateFriend(T1 name, T2 age)
	{
		this->Name = name;
		this->Age = age;
	}
	

private:
	T1 Name;
	T2 Age;
};


void ClassTemplateFriendcc()
{
	ClassTemplateFriend<string, int> ctf("����ʵ��",19);
	PrintPerson(ctf);
}

void ClassTemplateFriendcd()
{
	ClassTemplateFriend<string, int> ctf("����ʵ��", 199);
	PrintPerson2(ctf);
}

void main_ClassTemplateFriendcd()
{
	//ClassTemplateFriendcc();
	ClassTemplateFriendcd();
}