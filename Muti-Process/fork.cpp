#include <stdio.h>
#include <unistd.h>

//学习连接 http://freecplus.net/6b31f2b95bd54eec99480a07eeefabd4.html
// https://www.cnblogs.com/ittinybird/p/4492098.html
int main()
{
    printf("开启进程：%d\n",getpid());

    int newPid=fork();
    //当出现fork()函数，下面的代码就会出现两个进程，一个是子进程，一个是父进程，返回的值是子进程的ID
    //紧接着后面的代码段是一份，数据区（堆栈段（程序参数及局部变量等）+数据段（全局变量及常量等）））两个进程各一份，然后同时执行。
    int num=0;
    if (newPid!=0)//子进程代码段中这个ID自动是0，父进程代码段中这个ID是当前进程的ID
    {
        num++;
        printf("这段执行的是父进程代码段。PID=%d,num:%d，getpid：%d\n",newPid,num,getpid());//num打印的值应该是1，父进程中newPid就是子进程的ID
        sleep(10);
    }
    else
    {
        num++;
        printf("这段执行的是子进程代码段。PID=%d,num:%d,getpid：%d\n",newPid,num,getpid());//num打印的值应该是1,newPid应该是0，因为这块是在子进程代码段中
        sleep(9);
        if (fork()!=0)
        {
            printf("这段执行的是父进程代码段。PID=%d,getpid：%d\n",newPid,getpid());//num打印的值应该是1
        }
        else
        {
            printf("这段执行的是子进程代码段。PID=%d,getpid：%d\n",newPid,getpid());
        }
        
    }

    printf("随便打印下，我也不知道这是子还是父！%d\n",getpid());//这个会打印三次，因为上面出现了两个fork()

    return 0;
}