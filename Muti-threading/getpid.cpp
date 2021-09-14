/*
 * 程序名：book251.cpp，此程序用于演示获取程序运行时的进程编号
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
  printf("本程序的进程编号是：%d\n",getpid());
  sleep(30);    // 是为了方便查看进程在shell下用ps -ef|grep book251查看本进程的编号。
}