#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//线程函数中不能使用exit(),如果用了会让整个进程退出
void *mainfunc1(void *arg);
void *mainfunc2(void *arg);

int variable = 0;//这个全局变量来验证线程的数据是共享的。
//一个进程间的多个线程,子进程可以运行完exit。但线程不行，一旦子线程exit，整个进程就退掉了，但可以使用线程退出函数(pthread_exit())来退出。
//线程间的数据空间是共享的，也就是进程的数据空间
//编译此程序方法：gcc MutiThreadingDemo.cpp -o  MutiThreadingDemo -lpthread
int main()
{
    pthread_t pthID1, pthID2; //pthread_t:long unsigned

    //创建一个子线程
    if (pthread_create(&pthID1, NULL, mainfunc1, NULL) != 0)
    {
        printf("Create thread failed.\n");
        return -1;
    }
    //创建一个子线程
    if (pthread_create(&pthID2, NULL, mainfunc2, NULL) != 0)
    {
        printf("Create thread failed.\n");
        return -1;
    }

    printf("threadID=%lu,threadID=%lu\n", pthID1, pthID2); //%lu表示输出无符号长整型整数 (long unsigned)

    printf("Waiting ChildThread out!\n");

    pthread_join(pthID2, NULL);
    printf("ChildThread2 out.\n");

    pthread_join(pthID1, NULL);
    printf("ChildThread1 out.\n");

    return 1;
}

void *mainfunc1(void *arg)//void * 必须有返回值才行。只有纯void才不写return
{
    for (int i = 0; i < 5; i++)
    {
        variable++;
        sleep(1);
        printf("ChildThread1 sleep 1s (%d)\n", variable);
    }
    //  return (void*)0;//不写这一步会报警告：no return statement in function returning non-void [-Wreturn-type]
    pthread_exit(0);
}

void *mainfunc2(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        variable++;
        sleep(1);
        printf("ChildThread2 sleep 1s (%d)\n", variable);
    }

    // exit(0);//执行到这儿会让进程退掉，故而程序直接全部退掉

    // return (void*)0;
     pthread_exit(0);
}