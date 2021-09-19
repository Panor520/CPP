//�Լ���ͨ�õ�������
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
		cout << "����"<<endl;
		this->Capacity = capacity;
		this->pAddress = new T[this->Capacity];
		this->Size = 0;
	}
	MyArray(const MyArray& arr)
	{
		cout << "����" << endl;
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		//this->pAddress = arr.pAddress;//ǳ����д��
		this->pAddress = new T[arr.Capacity];

		//��arr�е����ݶ���������
		for (int i = 0; i < arr.Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= ��ֹǳ��������
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
		//���
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		this->pAddress = new T[arr.Capacity];
		//�����ݿ�������
		for (int i = 0; i < arr.Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//β�巨
	void Push_Back(const T &a)
	{
		//�������ڴ�С�Ͳ岻��ȥ��
		if (this->Size==this->Capacity)
		{
			return;
		}
		this->pAddress[this->Size] = a;
		this->Size++;
	}
	//βɾ��
	void Pop_Back()
	{
		//�����һ��Ԫ�ط��ʲ�����Ϊβɾ���߼�ɾ��
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

	//������������
	int getCapacity()
	{
		return this->Capacity;
	}
	//���������С
	int getSize()
	{
		return this->Size;
	}
	~MyArray()
	{
		cout << "����" << endl;
		if (this->pAddress!=NULL)
		{
			delete [] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//ָ��ָ��������ٵ���ʵ������

	int Capacity;//��������

	int Size;//��С
};