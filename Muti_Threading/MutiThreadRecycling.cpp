#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//线程回收参考链接：http://freecplus.net/c893ece166b94df4b2e185fa6f1c920c.html
//https://www.bilibili.com/video/BV1zf4y1Q7Nj?p=4
//正常写代码设置了对线程设置了分离状态就不会再设置pthread_join。

//线程中共享一个进程中的数据段
//GDB调试命令（加了-g）： gcc -g MutiThreadParameter.cpp -o  MutiThreadParameter -lpthread
// gdb MutiThreadParameter
void *threadfunc(void *arg);
void *threadfunc2(void *arg);


int main()
{
    //方法2
    // pthread_attr_t attr;
    // pthread_attr_init(&attr);
    // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置线程的属性。//引用这部分代码后，主线程退出后，子进程会交给系统托管后立即退出并释放资源

    pthread_t pID, pID2;

    // if (pthread_create(&pID, &attr, threadfunc, NULL)) //第二个参数是用来线程回收的
    if (pthread_create(&pID, NULL, threadfunc, NULL)) //第二个参数是用来线程回收的
    {
        printf("create thread failed\n");
        return -1;
    }
     pthread_detach(pID);//方法3 和方法2功能一样  参考链接http://freecplus.net/c893ece166b94df4b2e185fa6f1c920c.html


    // if (pthread_create(&pID2, NULL, threadfunc2, (void *)variable)) //强转换要特别注意，要注意64位linux指针是8字节
    // {
    //     printf("create thread failed\n");
    //     return -1;
    // }

    int res = pthread_join(pID, NULL); //上面创建线程时使用了第二个参数设置线程回收年的状态，那这一步就join不到了
    //int res2 = pthread_join(pID2, NULL);

    printf("thread out res= %d\n", res);//设置了分离状态会打印出22
    //printf("thread2 out res= %d", res2);//正常打印出0
    // sleep(5);
    return 0;
}

void *threadfunc(void *arg)
{
    //方法4 在子线程中设置状态修改
     pthread_detach(pthread_self());//这个地方要注意主线程jion时，如果这行没跑到就会jion到，故而主线程还是会等待子线程结束
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("ChildThread sleep 1s  \n" );
    }

    return (void *)0;
}

void *threadfunc2(void *arg)
{
    printf("this thread is num%ld\n", (long)arg);
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("ChildThread 2 sleep 1s (%ld) \n", (long)arg);
    }

    return (void *)0;
}
