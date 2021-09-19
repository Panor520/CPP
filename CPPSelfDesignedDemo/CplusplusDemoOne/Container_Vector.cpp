//vector动态扩展，新增元素时，不是在原有空间后面增加，而是新创建一个新的够容纳下新增后的所有数据的空间，将数据拷贝到新空间后，把原来的空间释放
//vector的迭代器是支持随机访问的，即可以v.begin()+n,n为常数1、2、3...

#include <vector>
#include <iostream>
using namespace std;

//template <class T>
void PrintVector(vector<int> &v)//非自定义类打印,vector做参数，必须先知道类型
{
	for (vector<int>::iterator it=v.begin(); it!=v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector默认构造
void vector_structure()
{
	vector<int> v1;//默认构造 无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	//通过区间方式进行构造
	vector<int> v2(v1.begin(),v1.end());
	PrintVector(v2);

	//n个元素方式构造
	vector<int> v3(10,1000);//10个1000
	PrintVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	PrintVector(v4);
}

//vector赋值操作
void vector_Assignment()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	//赋值 operator=
	vector<int> v2;
	v2 = v1;
	PrintVector(v2);

	//赋值 将v2从begin()位置到end()位置的数据拷贝给v3
	vector<int> v3;
	v3.assign(v2.begin(),v2.end());
	PrintVector(v3);

	//赋值 9个100
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
		cout << "capacity:" <<v1.capacity() <<endl;//容器的容量是随机分配的，肯定比size大
		cout << "size:" << v1.size() << endl;//
	}

	v1.resize(13);//重新设置大小，超过原来长度的部分默认为0
	cout << "size:" << v1.size() << endl;//
	PrintVector(v1);

	v1.resize(14,100);//重新设置大小，超过原来长度的部分默认为指定数字100
	cout << "size:" << v1.size() << endl;//
	PrintVector(v1);

	v1.resize(9);//重新设置大小，少于指定大小的部分会被删除
	cout << "size:" << v1.size() << endl;//
	PrintVector(v1);
}

//vector insert erase(擦除、清除)
void vector_insertErase()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{//尾插法
		v1.push_back(i);
	}
	PrintVector(v1);

	//尾删法
	v1.pop_back();
	PrintVector(v1);

	//迭代器位置增加一个元素
	v1.insert(v1.begin(),10);
	PrintVector(v1);
	//迭代器位置增加n=2个元素22
	v1.insert(v1.begin(),2,22);
	PrintVector(v1);

	//清除两个迭代器位置之间的数据
	v1.erase(v1.begin(),v1.end());
	//v1.clear();//等价于上面
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

	cout << "访问第一个元素：" << v1.front()<<endl;
	cout << "访问最后一个元素：" << v1.back() << endl;
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
	v1.swap(v2);//将v2中的元素于自身互换
	PrintVector(v1);
	PrintVector(v2);
	cout << &v1 << endl;
	cout << &v2 << endl;

	//利用swap收缩内存
	vector<int> v3;
	for (int i = 0; i < 10000; i++)
	{
		v3.push_back(i);
	}

	cout<<"交换前：" << v3.capacity() << endl;
	cout<<"交换前：" << v3.size() << endl;
	v3.resize(1);
	cout << "交换前：" << v3.capacity() << endl;
	cout << "交换前：" << v3.size() << endl;

	vector<int>(v3).swap(v3);//匿名对象vector<int>(v3)， 当前行被执行结束后即被系统自动清除。采用这种方式可收缩空间
	cout << "交换后：" << v3.capacity() << endl;
	cout << "交换后：" << v3.size() << endl;
}

//vector 预留空间Reserve
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
