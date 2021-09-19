//模板是泛型编程的基础
//在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。内联函数编译器会把该函数的代码副本放置在每个调用该函数的地方

#include <iostream>
using namespace std;

//函数模板示例：
template <typename T>
T  Max(T  a, T  b)
//inline T const& Max (T const& a, T const& b) 
{
	return a < b ? b : a;
}

int maintf()
{

    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

    return 0;
}