
#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {//c++中对于除以零问题不会catch到，需要自定义throw后，catch到
        throw "Division by zero condition!";
    }
    return (a / b);
}
//自定义异常
struct MyException :public exception
{
    const char* what() const throw ()
    {
        return "C++ Exception";
    }
};

int mainc()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char* msg) //获取try中Throw的信息
    {
        cerr << msg << endl;
    }

    try
    {
        throw MyException();
    }
    catch (MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        //其他的错误
    }

    return 0;
}