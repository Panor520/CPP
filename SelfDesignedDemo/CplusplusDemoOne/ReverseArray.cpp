#include <iostream>
using namespace std;

void ReverseArray(int *array,int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		int a = i;
		int b = len - i-1;

		//�����ִ��5��ѭ��
		/*if (a + 1 >= b - 1)
		{
			break;
		}*/
		count++;

		int temp = *(array + a);
		* (array + a) = *(array+b);
		*(array + b) = temp;

		//�����ִ��4��ѭ��,������������ã����Ӷ����
		if (a+1 >= b-1)
		{
			break;
		}
	}
	cout << "Count:" << count << endl;
}

void ShowArray1(int* array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *(array + i)<<" ";
	}
	cout << endl;
}

void mainReverse()
{
	int array[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(array) / sizeof(*array);
	cout << "Before:";
	ShowArray1(array, len);
	ReverseArray(array,len);
	cout << "After:";
	ShowArray1(array, len);

}