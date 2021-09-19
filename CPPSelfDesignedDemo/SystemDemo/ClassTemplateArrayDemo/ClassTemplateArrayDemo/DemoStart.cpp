#include "MyArray.hpp"

class Person
{
	friend void PrintArr1(MyArray<Person>& a);
public:
	Person() {};
	Person(string name, int age)
	{
		this->Name = name;
		this->Age = age;
	}
private:
	string Name;
	int Age;
};

template <class T>
void PrintArr(MyArray<T> &a)
{
	for (int i = 0; i < a.getSize(); i++)
	{
		cout << a[i] << endl;
	}
}

void PrintArr1(MyArray<Person> &a)
{
	for (int i = 0; i < a.getSize(); i++)
	{
		cout << a[i].Name<<" "<<a[i].Age << endl;
	}
}

void test01()
{
	MyArray<int> ma(5);
	/*MyArray<int> ma1(ma);
	MyArray<int> ma2(6);
	ma = ma2;*/
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		ma.Push_Back(i);
	}
	PrintArr(ma);

	ma.Pop_Back();
	PrintArr(ma);
}

void test02()
{
	MyArray<Person> arr(10);//此声明中，Person中一定要有默认空参数列表构造
	for (int i = 0; i < 10; i++)
	{
		Person  p =*( new Person("Tom",i+1));
		arr.Push_Back(p);
	}
	PrintArr1(arr);
	//尾删法删除一个，还可以打印出9个
	arr.Pop_Back();
	PrintArr1(arr);
}


void main()
{
	test01();

	test02();
}