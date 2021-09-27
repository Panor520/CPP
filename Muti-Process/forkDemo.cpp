#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

//如果只考虑fork机制下面的程序会打印出6个-
//但实际上会打印出8个-   哇哦，真的好神奇阿
//打出8个的原因：屏幕输出是行缓存模式；子进程会拷贝父进程的这部分缓存；子进程输出时会将这部分拷贝过来的缓存输出，而父进程的缓存不会输出
//参照：https://www.cnblogs.com/ittinybird/p/4492098.html
//https://www.cnblogs.com/qlee/archive/2011/07/27/2118406.html
int main(void)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        fork();
        printf("-");
    }

    wait(NULL);
    wait(NULL);

    return 0;
}