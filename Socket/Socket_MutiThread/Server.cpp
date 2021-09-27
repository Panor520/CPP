/*
 * 程序名：server.cpp，此程序用于演示socket通信的服务端
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <signal.h>
#include <vector>
using namespace std;

int exitflag;

void *pthMain(void *arg); //和客户端通信线程函数
void mainexit(int sig);   //信号处理函数

int commonlistenfd;          //主线程监听socket
vector<int> v_pid;           //用来存放和客户端通信的所有socket
void pthmainexit(void *arg); //子线程清理函数

int main(int argc, char *argv[])
{
    signal(2, mainexit);  //Ctrl+c
    signal(15, mainexit); //kill 或 killall

    if (argc != 2)
    {
        printf("Using:./server port\nExample:./server 5005\n\n");
        return -1;
    }

    // 第1步：创建服务端的socket。
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }
    commonlistenfd = listenfd;

    // 第2步：把服务端用于通信的地址和端口绑定到socket上。
    struct sockaddr_in servaddr; // 服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;                // 协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 任意ip地址。
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。
    servaddr.sin_port = htons(atoi(argv[1])); // 指定通信端口。
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }

    // 第3步：把socket设置为监听模式。
    if (listen(listenfd, 5) != 0)
    {
        perror("listen");
        close(listenfd);
        return -1;
    }

    while (1)
    {
        
        // 第4步：接受客户端的连接。
        int clientfd;                             // 客户端的socket。
        int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
        struct sockaddr_in clientaddr;            // 客户端的地址信息。
        clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
        if (exitflag == 1)//此块代码用来设置当没有客户端连接时，也能通过信号让程序正确退出。
        {
            break;
        }
        printf("客户端（%s）已连接。\n", inet_ntoa(clientaddr.sin_addr));

        //主线程负责监听，子进程负责和客户端通信
        pthread_t pID1;
        if (pthread_create(&pID1, NULL, pthMain, (void *)(long)clientfd) != 0)
        {
            printf("-----pthread_create failed!-----\n");
        }
        v_pid.push_back(pID1);
    }

    return 0;
}

void *pthMain(void *arg)
{
    int threadID = gettid();       //获取进程ID
    int tid = syscall(SYS_gettid); //获取线程ID
    int socketID = (int)(long)arg;

    pthread_cleanup_push(pthmainexit, arg);              //注册线程清理函数
    pthread_detach(pthread_self());                      //设置线程分离
    pthread_setcanceltype(PTHREAD_CANCEL_DISABLE, NULL); //设置cancel为立即取消

    char buffer[1024];
    while (1)
    {
        int iret;
        memset(buffer, 0, sizeof(buffer));
        if ((iret = recv(socketID, buffer, sizeof(buffer), 0)) <= 0) // 接收客户端的请求报文。
        {
            printf("iret=%d\n", iret);
            break;
        }
        printf("threadID=%d,%d, 接收：%s\n", threadID, tid, buffer);
        sleep(2);
        strcpy(buffer, "ok");
        if ((iret = send(socketID, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
        {
            perror("send");
            break;
        }
        printf("threadID=%d,%d,发送：%s\n", threadID, tid, buffer);
    }

    pthread_cleanup_pop(1);
    pthread_exit(0);
}

//信号处理函数
void mainexit(int sig)
{
    printf("---server exit begin\n");
    exitflag = 1;
    //close listen socket
    close(commonlistenfd);

    for (int i = 0; i < v_pid.size(); i++)
    {
        printf("thread cancel id=%d", v_pid[i]);
        pthread_cancel(v_pid[i]);
    }

    printf("---server exit end\n");
    //exit(0);
}

//子线程清理函数
void pthmainexit(void *arg)
{
    printf("---thread cleanup begin---\n");
    //关闭与客户端的socket
    close((int)(long)arg);

    //在线程容器中去掉本线程的值
    for (int i = 0; i < v_pid.size(); i++)
    {
        if (v_pid[i] == pthread_self())
        {
            printf("v_pid erase threadid=%ld", pthread_self());
            v_pid.erase(v_pid.begin() + i);
        }
    }
    printf("---thread cleanup end---\n");
}