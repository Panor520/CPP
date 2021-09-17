#include <unistd.h>
#include <cstdio>
int main()
{
	printf("本进程编号为：%d\n",getpid());
	sleep(10);
	return 0;
}
