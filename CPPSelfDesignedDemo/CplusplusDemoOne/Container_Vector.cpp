//vector��̬��չ������Ԫ��ʱ��������ԭ�пռ�������ӣ������´���һ���µĹ���������������������ݵĿռ䣬�����ݿ������¿ռ�󣬰�ԭ���Ŀռ��ͷ�
//vector�ĵ�������֧��������ʵģ�������v.begin()+n,nΪ����1��2��3...

#include <vector>
#include <iostream>
using namespace std;

//template <class T>
void PrintVector(vector<int> &v)//���Զ������ӡ,vector��������������֪������
{
	for (vector<int>::iterator it=v.begin(); it!=v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vectorĬ�Ϲ���
void vector_structure()
{
	vector<int> v1;//Ĭ�Ϲ��� �޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	//ͨ�����䷽ʽ���й���
	vector<int> v2(v1.begin(),v1.end());
	PrintVector(v2);

	//n��Ԫ�ط�ʽ����
	vector<int> v3(10,1000);//10��1000
	PrintVector(v3);

	//��������
	vector<int> v4(v3);
	PrintVector(v4);
}

//vector��ֵ����
void vector_Assignment()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	//��ֵ operator=
	vector<int> v2;
	v2 = v1;
	PrintVector(v2);

	//��ֵ ��v2��begin()λ�õ�end()λ�õ����ݿ�����v3
	vector<int> v3;
	v3.assign(v2.begin(),v2.end());
	PrintVector(v3);

	//��ֵ 9��100
	vector<int> v4;
	v4.assign(9,100);
	PrintVector(v4);
}

//vector capacity size
void vector_SizeCap()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	if (!v1.empty())
	{
		cout <<"Unempty" << endl;
		cout << "capacity:" <<v1.capacity() <<endl;//�������������������ģ��϶���size��
		cout << "size:" << v1.size() << endl;//
	}

	v1.resize(13);//�������ô�С������ԭ�����ȵĲ���Ĭ��Ϊ0
	cout << "size:" << v1.size() << endl;//
	PrintVector(v1);

	v1.resize(14,100);//�������ô�С������ԭ�����ȵĲ���Ĭ��Ϊָ������100
	cout << "size:" << v1.size() << endl;//
	PrintVector(v1);

	v1.resize(9);//�������ô�С������ָ����С�Ĳ��ֻᱻɾ��
	cout << "size:" << v1.size() << endl;//
	PrintVector(v1);
}

//vector insert erase(���������)
void vector_insertErase()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{//β�巨
		v1.push_back(i);
	}
	PrintVector(v1);

	//βɾ��
	v1.pop_back();
	PrintVector(v1);

	//������λ������һ��Ԫ��
	v1.insert(v1.begin(),10);
	PrintVector(v1);
	//������λ������n=2��Ԫ��22
	v1.insert(v1.begin(),2,22);
	PrintVector(v1);

	//�������������λ��֮�������
	v1.erase(v1.begin(),v1.end());
	//v1.clear();//�ȼ�������
	if (v1.empty())
	{
		cout << "empty" << endl;
	}
	PrintVector(v1);


}

//vector get element
void vector_GetElement()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//get element method 1
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i)<<" ";
	}
	cout<< endl;
	PrintVector(v1);

	//get element method 2
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	PrintVector(v1);

	cout << "���ʵ�һ��Ԫ�أ�" << v1.front()<<endl;
	cout << "�������һ��Ԫ�أ�" << v1.back() << endl;
}

//vector swap
void vector_swap()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	for (int i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}

	PrintVector(v1);
	PrintVector(v2);
	cout<<&v1 <<endl;
	cout << &v2 << endl;
	v1.swap(v2);//��v2�е�Ԫ����������
	PrintVector(v1);
	PrintVector(v2);
	cout << &v1 << endl;
	cout << &v2 << endl;

	//����swap�����ڴ�
	vector<int> v3;
	for (int i = 0; i < 10000; i++)
	{
		v3.push_back(i);
	}

	cout<<"����ǰ��" << v3.capacity() << endl;
	cout<<"����ǰ��" << v3.size() << endl;
	v3.resize(1);
	cout << "����ǰ��" << v3.capacity() << endl;
	cout << "����ǰ��" << v3.size() << endl;

	vector<int>(v3).swap(v3);//��������vector<int>(v3)�� ��ǰ�б�ִ�н����󼴱�ϵͳ�Զ�������������ַ�ʽ�������ռ�
	cout << "������" << v3.capacity() << endl;
	cout << "������" << v3.size() << endl;
}

//vector Ԥ���ռ�Reserve
void vector_reserve()
{
	int num=0;
	int* p = NULL;
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p!=&v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num=" << num << endl;




	int num1 = 0;
	int* p1 = NULL;
	vector<int> v1;
	v1.reserve(100000);
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);

		if (p1 != &v1[0])
		{
			p1 = &v1[0];
			num1++;
		}
	}

	cout << "num1=" << num1 << endl;
}

void main_vector()
{
	//vector_structure();
	//vector_Assignment();
	//vector_SizeCap();
	//vector_insertErase();
	//vector_GetElement();
	//vector_swap();
	vector_reserve();
}
