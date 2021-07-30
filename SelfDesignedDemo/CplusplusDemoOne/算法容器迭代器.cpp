//����������֮��Ҳ
//STL�������ǽ�������㷺��һЩ���ݽṹʵ�ֳ���
//���õ����ݽṹ�����顢��������ջ�����С����ϡ�ӳ����
//������Ϊ����ʽ�����͹���ʽ������
//����ʽ������ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ض��й̶���λ��
// ����һ������Ϊ{1,3,5,4,2}�������ﻹ��{1,3,5,4,2}
//����ʽ��������������򣩣��������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ
// ����һ������Ϊ{1,3,5,4,2}��������ͱ�Ϊ��{1,2,3,4,5}

//�㷨��Algorithms��������֮�ⷨҲ
//���޵Ĳ������߼�����ѧ�ϵ�����
//�㷨��Ϊ�ʱ��㷨�ͷ��ʱ��㷨
//�ʱ��㷨��ָ��������л���������ڵ�Ԫ�����ݡ����翽�����滻��ɾ���ȡ�
//���ʱ��㷨��ָ��������в�����������ڵ�Ԫ�����ݡ�������ҡ�������������Ѱ�Ҽ�ֵ�ȡ�

//
//�㷨ͨ�������еĵ��������ܷ��������е�Ԫ��

//ÿ�����������Լ�ר���ĵ�����
//������������ָ�룬��ѧ�߿�������������Ϊָ��
//---------------------------------------------------------------------------------------------------------------------
//-	����			  -  	    ����												-			֧������							 -		
//-���������	  -  �����ݵ�ֻ������											-	ֻ����֧��++��==����=					  	 -
//-���������	  -  �����ݵ�ֻд����											-	ֻд��֧��++								 -
//-ǰ�������	  -  ��д������������ǰ�ƽ�������								-	��д��֧��++��==����+					  	 -
//-˫�������	  -  ��д������������ǰ����ƽ�������							-	��д��֧��++��--						     -
//-������ʵ�����	  -  ��д��������������Ծ�ķ�ʽ�����������ݣ�������ǿ�ĵ�����		-	��д��֧��++��--��[n]��-n��<��<=��>��>=	 - 
//---------------------------------------------------------------------------------------------------------------------
//���õ���˫���������ʵ�����



//������һ��ʵ��
//Vector �������Ϊ���� ������ʹ��ʱ��Ҫ����ͷ�ļ�
//���롢��������
#include <vector>
#include <algorithm>//��׼�㷨ͷ�ļ�
#include <iostream>
#include <string>
using namespace std;

class vector_Person;
void vector_printPer(vector_Person& v);
void vector_printPer1(vector_Person* v);

class vector_Person
{
	friend void vector_printPer(vector_Person& v);
	friend void vector_printPer1(vector_Person* v);
	friend void vector_test03();
public:
	vector_Person(string name,int age)
	{
		this->Name = name;
		this->Age = age;
	}
private:
	string Name;
	int Age;
};

void vector_print(int x)
{
	cout<<x <<endl;
}

void vector_test01()
{
	vector<int> v;
	//β�巨
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//��������һ
	vector<int>::iterator itBegin = v.begin();//����vector��һ��Ԫ�ص�δ֪
	vector<int>::iterator itEnd = v.end(); //����vector���
	while (itBegin!=itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//����������
	for (vector<int>::iterator  it = v.begin(); it!=v.end(); it++)//iterator ������
	{
		//cout<<&it << endl;
		cout<<*it<<endl;
	}

	//���������� ����STL�ṩ�ķ���
	for_each(v.begin(), v.end(), vector_print);//ת������鿴�÷�����ϸ�߼�

}

void vector_printPer(vector_Person &v)
{
	cout << v.Name << " " << v.Age << endl;
}

void vector_printPer1(vector_Person * v)
{
	cout << (*v).Name << " " << (*v).Age << endl;
}

//�����д���Զ�������
void vector_test02()
{
	vector<vector_Person> v;
	vector_Person va("Tom",10);
	vector_Person va1("Tom1", 11);
	vector_Person va2("Tom2", 12);
	v.push_back(va);
	v.push_back(va1);
	v.push_back(va2);

	for_each(v.begin(),v.end(), vector_printPer);
}

//�����д���Զ�������ָ��
void vector_test03()
{
	vector<vector_Person*> v;
	vector_Person va("Tom", 10);
	vector_Person va1("Tom1", 11);
	vector_Person va2("Tom2", 12);
	v.push_back(&va);
	v.push_back(&va1);
	v.push_back(&va2);

	for_each(v.begin(), v.end(), vector_printPer1);
	for (vector<vector_Person*>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (*i)->Name<< " " << (*i)->Age << endl;
	}
}


void vector_printVV(vector<int> & v)
{
	for_each(v.begin(),v.end(), vector_print);
	cout << endl;
}

void vector_test04()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<vector<int>> vv;
	v1.push_back(1);
	v1.push_back(11);
	v1.push_back(111);
	v2.push_back(2);
	v2.push_back(22);
	v2.push_back(222);
	v3.push_back(3);
	v3.push_back(33);
	v3.push_back(333);
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);

	for (vector<vector<int>>::iterator i =vv.begin() ; i != vv.end(); i++)
	{
		/*vector<int> v = *i;
		for (vector<int>::iterator j = v.begin(); j != v.end(); j++)*/
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << (*j) << " ";
		}
		cout << endl;
	}
	cout << "for_each��" << endl;
	for_each(vv.begin(), vv.end(), vector_printVV);
}

void main_AlgorithmContainerIterator()
{
	/*vector_test01();
	vector_test02();
	vector_test03();*/
	vector_test04();
}