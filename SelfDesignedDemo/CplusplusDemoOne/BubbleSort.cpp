#include <iostream>
using namespace std;


void BubbleSort(int* arr, int len)
{
	int count = 0;
	for (int i = 0; i < len-1; i++)//���ѭ�������ѭ��len-1��
	{
		for (int j = 0; j <len-1-i; j++)//�ڲ��һ��ѭ��len-1��
		{
			if (arr[j] > arr[j+1])//����
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			count++;
		}
	}
	cout << "count:" << count <<endl;//��׼ֵΪ36
}

//ָ���ŵ���16���Ƶ�ַ������4���ֽڣ�32λ����ϵͳ��64λ����ϵͳΪ8���ֽڣ���
//��ָ���1�����൱�ڸ�ָ���Ӧ�ĵ�ַ����4���ֽ�,���ָ�����������飬���൱��ָ����һ��Ԫ��
void BubbleSortPointer(int* arr, int len)
{
	int count = 0;
	for (int i = 0; i < len - 1; i++)//���ѭ�������ѭ��len-1��
	{
		for (int j = 0; j < len - 1 - i; j++)//�ڲ��һ��ѭ��len-1��
		{
			if (*(arr+j) > *(arr+j + 1))//����
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
			count++;
		}
	}
	cout << "count:" << count << endl;//��׼ֵΪ36
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
	int arr[] = {6,5,3,7,4,8,2,9,1};//�������������һ�������һ��Ԫ�ص��׵�ַ
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