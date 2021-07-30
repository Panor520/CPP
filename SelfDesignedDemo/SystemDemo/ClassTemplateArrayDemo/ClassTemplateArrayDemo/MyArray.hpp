//自己的通用的数组类
#pragma once
#include <iostream>
#include <string>
using namespace std;


template <class T>
class MyArray
{
public :
	MyArray(int capacity)
	{
		cout << "构造"<<endl;
		this->Capacity = capacity;
		this->pAddress = new T[this->Capacity];
		this->Size = 0;
	}
	MyArray(const MyArray& arr)
	{
		cout << "拷贝" << endl;
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		//this->pAddress = arr.pAddress;//浅拷贝写法
		this->pAddress = new T[arr.Capacity];

		//将arr中的数据都拷贝过来
		for (int i = 0; i < arr.Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray &arr)
	{
		cout << "= overload" << endl;
		if (this->pAddress!=NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->Capacity = 0;
			this->Size = 0;
		}
		//深拷贝
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		this->pAddress = new T[arr.Capacity];
		//将数据拷贝过来
		for (int i = 0; i < arr.Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T &a)
	{
		//容量等于大小就插不进去了
		if (this->Size==this->Capacity)
		{
			return;
		}
		this->pAddress[this->Size] = a;
		this->Size++;
	}
	//尾删法
	void Pop_Back()
	{
		//让最后一个元素访问不到即为尾删，逻辑删除
		if (this->Size==0)
		{
			return;
		}
		this->Size--;
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->Size;
	}
	~MyArray()
	{
		cout << "析构" << endl;
		if (this->pAddress!=NULL)
		{
			delete [] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//指针指向堆区开辟的真实的数组

	int Capacity;//数组容量

	int Size;//大小
};