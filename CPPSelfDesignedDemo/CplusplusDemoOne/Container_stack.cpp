//stack 先进后出 first in last out
//只有顶端的数据元素才可以被外界利用，故栈不允许有遍历行为
//有大小 size()  可判断是否为空 empty()

#include <iostream>
#include <stack>
using namespace std;

// structure
void stack_demo()
{
	stack<int> s;//structure
	
 	for (int i = 0; i < 10; i++)
	{
		s.push(i);//向栈顶添加元素, 先添加的在栈底
	}

	stack<int> s1(s);//structure
	s1 = s;//assignment

	cout<<"栈顶元素为：" << s.top() << endl;
	if (!s.empty())
	{
		cout << "size=" << s.size() << endl;
		s.pop();//删除栈底元素
		cout << "after pop size=" << s.size() << endl;
	}

}

void main_stack()
{
	stack_demo();
}