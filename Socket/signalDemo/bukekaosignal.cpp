#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void executeTask()
{
    printf("execute task...\n");
}

void signalfunc(int sig)
{
    //设置某信号阻塞锁，然后在某一时刻再解锁
    sigset_t set;//创建信号集
    sigaddset(&set, 15);//添加信号
    sigfillset(&set);//将所有信号添加到集合集中
    sigprocmask(SIG_BLOCK, &set, NULL);//block  设置信号集状态

    printf("Code get signal：%d\n", sig);
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("sig%d:%d\n",sig,i);
    }
    sigprocmask(SIG_UNBLOCK, &set, NULL);//unblock  设置信号集状态
    
}

int main()
{
    signal(SIGINT, signalfunc);  //2 SIGINT:ctrl+c 不可靠信号
    signal(15, signalfunc); // 15        killall -15 bukekaosignal

    

    printf("task begin---\n");
    int ii;
    while (1)
    {
        ii++;
        sleep(1);
        executeTask();
    }

    return 0;
}