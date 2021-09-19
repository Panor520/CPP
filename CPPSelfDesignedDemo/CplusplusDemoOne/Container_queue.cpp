//queue 先进先出 first in first out
//队尾		队头 
//入队		出队
//push		pop
//back      front
//不允许有遍历行为,只有队头队尾能被外界访问

#include <iostream>
#include <queue>
using namespace std;

void queue_demo()
{
	//structure
	queue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);//往队尾添加元素
	}

	//structure
	queue<int> q1(q);
	queue<int> q2;
	//assignment
	q2 = q;

	if (!q2.empty())
	{
		cout << "q2 size=" << q2.size() << endl;
		cout << "get front elem=" << q2.front() << endl;
		cout << "get last elem=" << q2.back() << endl;
		q2.pop();//erase first elem  pop()删除的都是先进的元素
		cout << "get after front elem=" << q2.front() << endl;
		cout << "get after last elem=" << q2.back() << endl;
	}

}

void main_queue()
{
	queue_demo();
}