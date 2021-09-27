//C++ �źŴ�����ṩ�� signal ��������������ͻ���¼�

#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received." << endl;

	// �����ر�
	// ��ֹ����  
	exit(signum);
}

//�� Ctrl+C ���жϳ���
void testsignal()
{
    // ע���ź� SIGINT ���źŴ������
    signal(SIGINT, signalHandler);

    while (1) {
        cout << "Going to sleep...." << endl;
        Sleep(1000);
    }
}
//ʹ��raise()�����������ж��źš�
void testRaise()
{
    int i = 0;
    // ע���ź� SIGINT ���źŴ������
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