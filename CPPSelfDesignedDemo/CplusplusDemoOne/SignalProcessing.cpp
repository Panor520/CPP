//C++ 信号处理库提供了 signal 函数，用来捕获突发事件

#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received." << endl;

	// 清理并关闭
	// 终止程序  
	exit(signum);
}

//按 Ctrl+C 来中断程序，
void testsignal()
{
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while (1) {
        cout << "Going to sleep...." << endl;
        Sleep(1000);
    }
}
//使用raise()函数来生成中断信号。
void testRaise()
{
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while (++i) {
        cout << "Going to sleep...." << endl;
        if (i == 3) {
            raise(SIGINT);
        }
        Sleep(1);
    }
}
void mainsp()
{
    //testsignal();
    testRaise();

}