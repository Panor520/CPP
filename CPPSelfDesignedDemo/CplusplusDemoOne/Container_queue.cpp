//queue �Ƚ��ȳ� first in first out
//��β		��ͷ 
//���		����
//push		pop
//back      front
//�������б�����Ϊ,ֻ�ж�ͷ��β�ܱ�������

#include <iostream>
#include <queue>
using namespace std;

void queue_demo()
{
	//structure
	queue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);//����β���Ԫ��
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
		q2.pop();//erase first elem  pop()ɾ���Ķ����Ƚ���Ԫ��
		cout << "get after front elem=" << q2.front() << endl;
		cout << "get after last elem=" << q2.back() << endl;
	}

}

void main_queue()
{
	queue_demo();
}