
#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {//c++�ж��ڳ��������ⲻ��catch������Ҫ�Զ���throw��catch��
        throw "Division by zero condition!";
    }
    return (a / b);
}
//�Զ����쳣
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
    catch (const char* msg) //��ȡtry��Throw����Ϣ
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
        //�����Ĵ���
    }

    return 0;
}