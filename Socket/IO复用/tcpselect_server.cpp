#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>

//当新的客户端连上来时，会按照从小到大找到可用的来分配
// 初始化服务端的监听端口。
int initserver(int port);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: ./tcpselect port\n");
        return -1;
    }

    // 初始化服务端用于监听的socket。
    int listensock = initserver(atoi(argv[1]));
    printf("listensock=%d\n", listensock);

    if (listensock < 0)
    {
        printf("initserver() failed.\n");
        return -1;
    }

    //创建结构体
    fd_set readfdset; // 读事件的集合，包括监听socket和客户端连接上来的socket。fd_set的存储是一个位图 bitmap，共1024bit
    int maxfd;        // readfdset中socket的最大值。

    // 清空初始化结构体
    FD_ZERO(&readfdset);//FD_ZERO将指定的文件描述符集清空，在对文件描述符集合进行设置前，必须对其进行初始化，如果不清空，由于在系统分配内存空间后，通常并不作清空处理，所以结果是不可知的。
    
    //把listensock添加到集合中，后面select中如果发生事件的是这个监听的socket就说明有新的客户端连接上来了
    FD_SET(listensock, &readfdset);//FD_SET用于在文件描述符集合中增加一个新的文件描述符，

    maxfd = listensock;//每次新增加socket都是在原来的socket上进行++操作

    while (1)
    {
        // 调用select函数时，会改变socket集合的内容，所以要把socket集合保存下来，传一个临时的给select。
        //select会将传进去的FD_SET的bitmap作修改，仅保留发生事件的socket的位；这也就是为什么这里要建副本的原因。
        //这个拷贝一般为1024/8=128字节（Byte）。
        fd_set tmpfdset = readfdset;

        //超时机制参数示例，如果select第五个参数设置了这个，如果5秒select的第二个参数中的所有socket没有事件发生就会出现timeout
        struct timeval sttime;
        sttime.tv_sec=5;
        sttime.tv_usec=0;

        //select中tmpfdset集合中任意一个socket有事件（新客户端连接、已连接客户端的请求）发生都会返回。select的返回值有两种，可由下面看出
        //select第一个参数代表位图使用的大小，最大为1024；如果不设置这个参数，那么select阻塞等待事件发生时会始终遍历整个fd_set的位图。
        //select第二个参数是读数据使用，用法就是本文
        //select第三个参数是写数据使用，一般置为空，用法自行百度
        //select第四个参数是监测有异常的集合，一般置为空，用法自行百度
        //select第五个参数是超时机制采用的参数，一般置为空，用法自行百度
        //select返回值-1失败：系统内存满了、给了错误的fdset集合、发送未知的信号（会直接中断服务程序，不会返回这个错误）
        //            0超时：如果第五个参数设置了超时时间这个就会起作用
        //            n成功：返回第二个参数集合中发生事件的socket的个数 
        int infds = select(maxfd + 1, &tmpfdset, NULL, NULL, NULL);//select功能类似与accept
        // printf("select infds=%d\n",infds);

        // 返回失败。
        if (infds < 0)
        {
            printf("select() failed.\n");
            perror("select()");
            break;
        }

        // 超时，在本程序中，select函数最后一个参数为空，不存在超时的情况，但以下代码还是留着。
        if (infds == 0)
        {
            printf("select() timeout.\n");
            continue;
        }

        // 检查有事情发生的socket，包括监听和客户端连接的socket。
        // 这里是客户端的socket事件，每次都要遍历整个集合，因为可能有多个socket有事件。
        for (int eventfd = 0; eventfd <= maxfd; eventfd++)
        {
            if (FD_ISSET(eventfd, &tmpfdset) <= 0)//FD_ISSET用于测试指定的文件描述符是否在该集合中，正常肯定是在这个集合中的
                continue;

            if (eventfd == listensock)//如果发生事件的是之前tmpfdset中定义的监听socket,就执行下面的代码
            {
                // 如果发生事件的是listensock，表示有新的客户端连上来。
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                int clientsock = accept(listensock, (struct sockaddr *)&client, &len);
                if (clientsock < 0)
                {
                    printf("accept() failed.\n");
                    continue;
                }

                printf("client(socket=%d) connected ok.\n", clientsock);

                // 把新的客户端socket加入集合。
                FD_SET(clientsock, &readfdset);

                if (maxfd < clientsock)
                    maxfd = clientsock;

                continue;
            }
            else
            {
                // 客户端有数据过来或客户端的socket连接被断开。
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));

                // 读取客户端的数据。
                //如果这个read函数第三个参数设置的比接收到的buffer的实际大小小，那么select会立即再次获取到客户端发送的数据的事件，并再次触发这个函数，而且响应的还是原来的事件ID；并不会丢失掉数据
                ssize_t isize = read(eventfd, buffer, sizeof(buffer));

                // 发生了错误或socket被对方关闭，就要把这个socket从集合中去掉并关闭
                if (isize <= 0)
                {
                    printf("client(eventfd=%d) disconnected.\n", eventfd);

                    // 关闭客户端的socket。
                    close(eventfd); 

                    // 从集合中移去客户端的socket。
                    FD_CLR(eventfd, &readfdset); //用于在文件描述符集合中删除一个文件描述符

                    // 重新计算maxfd的值，注意，只有当eventfd==maxfd时才需要计算。
                    if (eventfd == maxfd)
                    {
                        for (int ii = maxfd; ii > 0; ii--)
                        {
                            if (FD_ISSET(ii, &readfdset))
                            {
                                maxfd = ii;
                                break;
                            }
                        }

                        printf("maxfd=%d\n", maxfd);
                    }

                    continue;
                }

                printf("recv(eventfd=%d,size=%ld):%s\n", eventfd, isize, buffer);

                // 把收到的报文发回给客户端。
                write(eventfd, buffer, strlen(buffer));
            }
        }
    }

    return 0;
}

int initserver(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("socket() failed.\n");
        return -1;
    }

    // Linux如下
    int opt = 1;
    unsigned int len = sizeof(opt);
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, len);
    setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &opt, len);

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("bind() failed.\n");
        close(sock);
        return -1;
    }

    if (listen(sock, 5) != 0)
    {
        printf("listen() failed.\n");
        close(sock);
        return -1;
    }

    return sock;
}