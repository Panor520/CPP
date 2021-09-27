#include <iostream>
using namespace std;

void main()
{
	int a = 11; 
	int* b = &a;
	int c = *b;

	cout << sizeof(b) << endl;
}