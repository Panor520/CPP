#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <cstring>

void executeTask()
{
    printf("execute task...\n");
}

void handlerfunc(int sig)
{
    printf("Code get signal：%d\n", sig);
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("sig%d:%d\n",sig,i);
    }
    
}

int main()
{
    // signal(SIGINT, signalfunc);  //2 SIGINT:ctrl+c 不可靠信号
    // signal(15, signalfunc); // 15        killall -15 bukekaosignal

    struct  sigaction stact;
    memset(&stact,0,sizeof(stact));//初始化
    stact.sa_handler=handlerfunc;//指定信号处理函数
    // stact.sa_flags=SA_RESTART;//如果信号中断了进程的某个系统调用，则系统自动启动该系统调用。
    sigaddset(&stact.sa_mask,15);//指定阻塞
    
    sigaction(2,&stact,NULL);//指定信号2的处理行为
    sigaction(15,&stact,NULL);//指定信号15的处理行为

    printf("task begin---\n");
    char str[20];
    scanf("%s",str);
    printf("%s\n",str);
    // int ii;
    // while (1)
    // {
    //     ii++;
    //     sleep(1);
    //     executeTask();
    // }

    return 0;
}