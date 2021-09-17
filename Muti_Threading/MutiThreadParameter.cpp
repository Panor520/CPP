#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//线程中共享一个进程中的数据段
//GDB调试命令（加了-g）： gcc -g MutiThreadParameter.cpp -o  MutiThreadParameter -lpthread
// gdb MutiThreadParameter
void * threadfunc(void *arg);
void * threadfunc2(void *arg);
void * threadfunc3(void *arg);
void * threadfunc4(void *arg);

long variable=1;

int main()
{
    int xx=10;
    void *ptr=(void*)(long)xx;
    int yy=(int)(long)ptr;
    pthread_t pID,pID2,pID3,pID4;

    if (pthread_create(&pID,NULL,threadfunc,NULL))
    {
        printf("create thread failed\n");
        return -1;
    }
    variable++;//利用传参的方式，可以将全局变量的值带入到每个线程中
    if (pthread_create(&pID2,NULL,threadfunc2,(void*)variable))//强转换要特别注意，要注意64位linux指针是8字节
    {
        printf("create thread failed\n");
        return -1;
    }
    variable++;
    if (pthread_create(&pID2,NULL,threadfunc3,(void*)variable))//强转换要特别注意，要注意64位linux指针是8字节
    {
        printf("create thread failed\n");
        return -1;
    }
    variable++;
    if (pthread_create(&pID2,NULL,threadfunc4,(void*)variable))//强转换要特别注意，要注意64位linux指针是8字节
    {
        printf("create thread failed\n");
        return -1;
    }

    pthread_join(pID,NULL);
    pthread_join(pID2,NULL);
    pthread_join(pID3,NULL);
    pthread_join(pID4,NULL);
    return 0;
}

void * threadfunc(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("ChildThread sleep 1s (%ld) \n",variable);
    }

    return (void*)0;
}

void * threadfunc2(void *arg)
{
    printf("this thread is num%ld\n",(long)arg);
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("ChildThread 2 sleep 1s (%ld) \n",(long)arg);
    }

    return (void*)0;
}

void * threadfunc3(void *arg)
{
    printf("this thread is num%ld\n",(long)arg);
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("ChildThread 3 sleep 1s (%ld) \n",(long)arg);
    }

    return (void*)0;
}

void * threadfunc4(void *arg)
{
    printf("this thread is num%ld\n",(long)arg);
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("ChildThread 4 sleep 1s (%ld) \n",(long)arg);
    }

    return (void*)0;
}