#include <stdio.h>
#include <iostream>
using namespace std;

//this��ָ����������ָ�룬* this���������
//
//Ҳ����˵return* this���ص��ǵ�ǰ����Ŀ�¡���߱�������������ΪA�� ���ǿ�¡�� ����������ΪA& �� ���Ǳ��� ����
//
//return this���ص�ǰ����ĵ�ַ��ָ��ǰ�����ָ�룩

class MyNum
{
	friend ostream& operator<<(ostream& out, MyNum n);
public:
	MyNum()
	{
		m_Num = 0;
	}
	//ǰ�õ�����������
	//overload ǰ��++
	MyNum& operator++()//�����������ͣ����Ƿ��ض����� //�����������޷�ʵ��Ƕ��++��Ч��
	{
		m_Num++;
		return *this;
	}
	//overload ����++   ���õ�������ֵ
	//MyNum operator++(int) int��һ��ռλ��������������ǰ�úͺ��õ���
	MyNum operator++(int)//�����������ͣ����Ƿ��ض�����
	{
		//�ȼ�¼���
		MyNum temp=*this;
		//�����
		m_Num++;
		//��󷵻ؼ�¼�Ľ��
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream &out,MyNum n)
{
	out << n.m_Num;
	return out;
}
void testPP()
{
	MyNum m;
	cout << m << endl;//��Ҫ�������������
	cout << ++m << endl;
	cout << ++(++m) << endl;

	MyNum n;
	cout << n << endl;
	cout << n++ << endl;
	cout << n << endl;
}
void main_pp()
{
	testPP();
}