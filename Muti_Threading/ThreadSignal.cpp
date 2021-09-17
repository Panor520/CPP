#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

//在任何子线程中使用了信号处理函数，那所有线程的相应信号处理都会被改变。所以信号处理函数一般都只有一个

void *threadFunc(void *arg);

void hdfunc(int sig);

int main()
{
    
    signal(2, hdfunc);//这个捕获信号的代码放在主线程或子线程函数中都可以。
    pthread_t pID;
    if (pthread_create(&pID, NULL, threadFunc, NULL) != 0)
    {
        printf("---CREATE THREAD FAILED---\n");
    }

    // char str[50];
    // scanf("%s",str);//不会对子线程造成中断,而是会阻塞在子线程函数执行完后主线程的scanf的地方，而进程会直接造成中断。
    // printf("str=%s\n",str);

    pthread_kill(pID,2);//主线程向子线程发送信号用此函数，此时子线程会中断
                        //如果不设置线程信号处理函数，那么这里会将父子线程全部杀死。

    int ival;
    printf("-wait for the child thread to end\n");
    int result = pthread_join(pID, (void **)&ival); //子线程未设置为分离状态时（默认就是非分离的）可以获取到pthread_join的返回值，正常总是返回0，
                                                    //pthread_join第二个参数线程函数的返回值，也就是pthread_create指定的线程函数的返回值。
                                                    //如果线程被取消这个会返回-1，而不是指定的返回值
    printf("-child thread end (result=%d,ival=%d)\n", result, ival);

    return 0;
}

void *threadFunc(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("Child thread sleep %ds\n",i);
    }
    pthread_exit(0);
}

void hdfunc(int sig)
{
    printf("sig=%d\n",sig);
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf("--Get signal:%d sleep %ds\n",sig,i);
    }
    // pthread_exit(0);//这里加这个会让子线程直接退出。不加的话，会让子线程接着跑
}