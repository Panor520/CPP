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

    sleep(2);
    pthread_cancel(pID);
    int ival;
    
    printf("-wait for the child thread to end\n");
    int result = pthread_join(pID, (void **)&ival);
    printf("-child thread end (result=%d,ival=%d)\n", result, ival);
    return 0;
}

void *threadFunc(void *arg)
{
    int oldstate;
    // pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&oldstate);//main函数中pthread_cancel会失效
    // pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,&oldstate);
    // pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&oldstate);//立即取消
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,&oldstate);//延迟取消

    for (int i = 0; i < 3; i++)
    {
        // pthread_cleanup_push(cleanfunc1,NULL);//push和下面的pop必须在同一个作用域中成对出现
        sleep(3);
        printf("child thread sleep 1s\n"); //加\n清除缓存问题
        // pthread_cleanup_pop(1);
    }

    pthread_exit((void*)10);//pthread_exit返回结果时即使上面有注册清理函数也不影响这个返回结果。正常我们就用这个来返回线程函数结果。
    // return (void*)333;//return返回结果时，不会执行上面注册的所有清理函数。但实际还是会执行，这里留下个疑问？
}