//deque
//˫�����飬���Զ�ͷ�˺�β�˽��в���ɾ������
//��vector����
//vectorͷ��ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//deque��Զ��Զ�ͷ������ɾ���ٶȱ�vector��
//vector���������ڴ�ռ䣩����Ԫ���ٶȱ�deque��
//deque���ڲ�ʵ�����п���+������
//�п���������ά����������ַ
//�������д������

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printdeque(deque<int> &d)
{
	for (deque<int>::const_iterator i = d.begin(); i !=d.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//deque structure
void deque_structure()
{
	deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printdeque(d);

	//Structure method 1
	deque<int> d1(d.begin(),d.end());
	printdeque(d1);

	//structure method 2
	deque<int> d2(10,11);
	printdeque(d2);

	//structure method 3
	deque<int> d3(d2);
	printdeque(d3);
}

//deque assign
void deque_assign()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printdeque(d);

	deque<int> d1;
	d1 = d;
	printdeque(d);

	deque<int> d2;
	d2.assign(d.begin(),d.end());
	printdeque(d2);

	deque<int> d3;
	d3.assign(5,12);
	printdeque(d3);
}

//deque resize
void deque_resize()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printdeque(d);

	if (!d.empty())
	{
		cout << "unempty" << endl;
		cout << "" << d.size() << endl;
	}

	d.resize(7);//ɾ���³���֮�������
	printdeque(d);

	d.resize(10);//���������Ĵ�СĬ����0���
	printdeque(d);

	d.resize(15,11);//���������Ĵ�С��ָ������11���
	printdeque(d);

	d.resize(5,22);
	printdeque(d);
}

//deque insertdelete
void deque_insertdel()
{
	deque<int> d;
	for (int i = 5; i < 10; i++)
	{
		d.push_back(i);//β��
	}
	printdeque(d);
	for (int i = 0; i < 5; i++)
	{
		d.push_front(i);//ͷ��
	}
	printdeque(d);

	d.pop_back();//βɾ
	printdeque(d);
	d.pop_front();//ͷɾ
	printdeque(d);

	//��ָ��λ��(���λ�ñ����ǵ�����)����һ��Ԫ�صĿ��������������ݵ�λ��
	deque<int>::iterator x= d.insert(d.begin(),111);
	cout <<"add 111:" << *x << endl;
	printdeque(d);

	d.insert(d.end(),2,00);
	printdeque(d);

	deque<int> d1;
	////��ָ��λ��(���λ�ñ����ǵ�����)����d.begin(),d.end()֮������ݣ��޷���ֵ
	d1.insert(d1.begin(),d.begin(),d.end());
	printdeque(d1);

	//���
	//d1.clear();
	d1.erase(d1.begin(),d1.end());//������һ������λ��
	printdeque(d1);

	deque<int>::iterator I =  d.erase(d.begin());//������һ������λ��
	cout<<"d erase index:" << *I << endl;
	printdeque(d);
}

//deque data��ȡ
void deque_cunqu()
{
	deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	cout <<"get first elem:" << d.front() << endl;
	cout << "get last elem:" << d.back() << endl;
}

//deque sort
void deque_sort()
{
	deque<int> d;
	d.push_back(3);
	d.push_back(6);
	d.push_back(2);
	d.push_back(7);
	d.push_back(4);
	d.push_back(1);
	d.push_back(5);

	printdeque(d);
	sort(d.begin(),d.end());//Ĭ�ϴ�С����
	printdeque(d);
}

void main_deque()
{
	//deque_structure();
	//deque_assign();
	//deque_resize();
	//deque_insertdel();
	//deque_cunqu();
	deque_sort();
}