#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunc(void *arg);

//线程清理函数中一般写子线程的释放资源和锁，回滚事物等
void cleanfunc1(void *arg);
void cleanfunc2(void *arg);
void cleanfunc3(void *arg);

int main()
{
    pthread_t pID;
    if (pthread_create(&pID, NULL, threadFunc, NULL) != 0)
    {
        printf("---CREATE THREAD FAILED---");
    }
    int ival;
    // sleep(4);
    // pthread_cancel(pID);//cancel线程，注册的清理函数一定会被执行（如果cancel时pop还没被执行到，那就会被全部执行；否则会按照pop中的参数来执行）；
    printf("-wait for the child thread to end\n");
    int result = pthread_join(pID, (void **)&ival); //子线程未设置为分离状态时（默认就是非分离的）可以获取到pthread_join的返回值，正常总是返回0，
                                                    //pthread_join第二个参数线程函数的返回值，也就是pthread_create指定的线程函数的返回值。
                                                    //如果线程被取消这个会返回-1，而不是指定的返回值
    printf("-child thread end (result=%d,ival=%d)\n", result, ival);
    return 0;
}

void *threadFunc(void *arg)
{
    long para=222;
    //注册清理函数
    //每个清理函数都要注册，一般每个线程里只需要注册一个
    //注意：后面pop时是按注册的反顺序进行pop的
    pthread_cleanup_push(cleanfunc1,(void*)para);//第二个参数是用来给第一个参数的函数传参的
    pthread_cleanup_push(cleanfunc2,NULL);
    pthread_cleanup_push(cleanfunc3,NULL);

    for (int i = 0; i < 3; i++)
    {
        // pthread_cleanup_push(cleanfunc1,NULL);//push和下面的pop必须在同一个作用域中成对出现
        sleep(1);
        printf("child thread sleep 1s\n"); //加\n清除缓存问题
        // pthread_cleanup_pop(1);
    }

    //弹出线程清理函数
    //参数为0就弹出函数但不执行，为大于0的整数就弹出并执行
    //上面注册了几个，这个地方就相应的要pop几次，否则会报错
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(0);//参数为0就弹出函数但不执行，故threadfunc2未执行
    pthread_cleanup_pop(1);

    pthread_exit((void*)10);//pthread_exit返回结果时即使上面有注册清理函数也不影响这个返回结果。正常我们就用这个来返回线程函数结果。
    // return (void*)333;//return返回结果时，不会执行上面注册的所有清理函数。但实际还是会执行，这里留下个疑问？
}

void cleanfunc1(void *arg)
{
    printf("call cleanfunc1 arg=%ld.\n",(long)arg);
}
void cleanfunc2(void *arg)
{
    printf("call cleanfunc2.\n");
}
void cleanfunc3(void *arg)
{
    printf("call cleanfunc3.\n");
}