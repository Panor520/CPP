#include <iostream>
using namespace std;

#define PI 3.14159
#define MIN(a,b) (a<b ? a : b)
#define DEBUG
#define MKSTR( x ) #x
#define concat(a, b) a ## b

int mainpc()
{
	cout << "Value of PI :" << PI << endl;

	int i, j;
	i = 100;
	j = 30;
	cout << "较小的值为：" << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Inside main function" << endl;
#endif

#if 0
	/* 这是注释部分 */
	cout << MKSTR(HELLO C++) << endl;
#endif

	cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main function" << endl;
#endif

	cout << MKSTR(HELLO C++) << endl;
	cout << concat("HELLO"," C++") << endl;

	cout << "Value of __LINE__ : " << __LINE__ << endl;
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	cout << "Value of __TIME__ : " << __TIME__ << endl;
	return 0;
}