#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void executeTask()
{
    printf("execute task...\n");
}

void signalfunc(int sig)
{
    printf("Code get signal：%d", sig);
}

int main()
{
    signal(SIGINT, signalfunc);  //2 SIGINT:ctrl+c
    signal(SIGTERM, signalfunc); //15 SIGTERM:kill
    printf("task begin---");
    while (1)
    {
        sleep(2);
        executeTask();
    }

    return 0;
}