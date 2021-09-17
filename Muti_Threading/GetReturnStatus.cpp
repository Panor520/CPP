#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunc(void *arg);

int main()
{
    pthread_t pID;
    if (pthread_create(&pID, NULL, threadFunc, NULL) != 0)
    {
        printf("---CREATE THREAD FAILED---");
    }
    // usleep(150000);
    usleep(2000);//这一步sleep是为了避免子线程跑完了，而下面的cancel还没执行，导致认为cancel无效
    pthread_cancel(pID);//取消线程
    int ival;
    printf("-wait for the child thread to end\n");
    int result = pthread_join(pID,(void**)&ival);//子线程未设置为分离状态时（默认就是非分离的）可以获取到pthread_join的返回值，正常总是返回0，
                                                //pthread_join第二个参数线程函数的返回值，也就是pthread_create指定的线程函数的返回值。
                                                //如果线程被取消这个会返回-1，而不是指定的返回值
    printf("-child thread end (result=%d,ival=%d)\n",result,ival);
    return 0;
}

void * threadFunc(void * arg)
{
    // pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);//会让pthread_cancel失效，和pthread_cancel配合使用，如果不设置这行代码，默认就是PTHREAD_CANCEL_ENABLE，第二个参数是线程老的状态
    // pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);//默认就是PTHREAD_CANCEL_DEFERRED：表示立即取消
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);//PTHREAD_CANCEL_ASYNCHRONOUS表示延迟取消，直到一个取消点函数执行完后取消。
                                                            //取消点函数有很多，常用的printf,sleep都是取消点
    // for (int i = 0; i < 3; i++)
    // {
    //     sleep(1);
    //     printf("child thread sleep 1s\n");//加\n清除缓存问题
    // }
    int j=0;
    for (int anceltype = 0; anceltype < 50000; anceltype++)
    {
        j++;
    }
    printf("j=%d\n",j);
    // pthread_exit(0);
    // pthread_exit((void*)11);
    // return 0;
    return (void*)111;
    //上面的两种返回类型是相同的，都可以让pthread_join的第二个参数获取到返回值。
    //返回的结果是指针，而不是数字
}