//stack �Ƚ���� first in last out
//ֻ�ж��˵�����Ԫ�زſ��Ա�������ã���ջ�������б�����Ϊ
//�д�С size()  ���ж��Ƿ�Ϊ�� empty()

#include <iostream>
#include <stack>
using namespace std;

// structure
void stack_demo()
{
	stack<int> s;//structure
	
 	for (int i = 0; i < 10; i++)
	{
		s.push(i);//��ջ�����Ԫ��, ����ӵ���ջ��
	}

	stack<int> s1(s);//structure
	s1 = s;//assignment

	cout<<"ջ��Ԫ��Ϊ��" << s.top() << endl;
	if (!s.empty())
	{
		cout << "size=" << s.size() << endl;
		s.pop();//ɾ��ջ��Ԫ��
		cout << "after pop size=" << s.size() << endl;
	}

}

void main_stack()
{
	stack_demo();
}