#include <iostream>
using namespace std;


template <typename T>
void MySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i+1; j < len ; j++)
		{
			if (arr[j] < arr[max])
			{
				max = j;
			}
		}
		if (max != i)
		{
			T temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

template <typename T>
void PrintFunc(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *(arr + i) << endl;
	}
}

void FuncTemplatetest01()
{
	char chArr[] = "dcfaeb";
	int len = sizeof(chArr)/sizeof(*chArr);
	MySort(chArr, len);
	PrintFunc(chArr, len);
}

void FuncTemplatetest02()
{
	int arr[] = {3,2,4,5,1};
	int len = sizeof(arr)/sizeof(*arr);
	MySort(arr, len);
	PrintFunc(arr, len);
}

void main_FuncTemplatetest02()
{
	//FuncTemplatetest01();
	FuncTemplatetest02();
}