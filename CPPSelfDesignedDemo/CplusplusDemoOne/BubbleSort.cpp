#include <iostream>
using namespace std;


void BubbleSort(int* arr, int len)
{
	int count = 0;
	for (int i = 0; i < len-1; i++)//外层循环，最多循环len-1次
	{
		for (int j = 0; j <len-1-i; j++)//内层第一次循环len-1次
		{
			if (arr[j] > arr[j+1])//正序
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			count++;
		}
	}
	cout << "count:" << count <<endl;//标准值为36
}

//指针存放的是16进制地址，都是4个字节（32位操作系统，64位操作系统为8个字节），
//给指针加1，就相当于给指针对应的地址增加4个字节,如果指针代表的是数组，就相当于指向下一个元素
void BubbleSortPointer(int* arr, int len)
{
	int count = 0;
	for (int i = 0; i < len - 1; i++)//外层循环，最多循环len-1次
	{
		for (int j = 0; j < len - 1 - i; j++)//内层第一次循环len-1次
		{
			if (*(arr+j) > *(arr+j + 1))//正序
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
			count++;
		}
	}
	cout << "count:" << count << endl;//标准值为36
}

void ShowArray(int *arr,int len)
{
	cout << "Array:";
	for (int i = 0; i < len; i++)
	{
		cout <<arr[i] << " ";
	}
	cout << endl;
}

void mainBubbleSort()
{
	int arr[] = {6,5,3,7,4,8,2,9,1};//数组名本身就是一个数组第一个元素的首地址
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "Before BubbleSort:" << endl;
	ShowArray(arr, len);
	//BubbleSort(arr, len);
	BubbleSortPointer(arr, len);
	cout << "After BubbleSort:" << endl;
	ShowArray(arr, len);

	long long int x = 10;
	long long int* p;
	cout << sizeof(p)<<endl;
	p = &x;
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;
}