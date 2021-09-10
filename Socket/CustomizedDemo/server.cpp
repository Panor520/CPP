#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Warning:Parameters must be set!\nPls Using:./server portNumber\nExample:./server 5005\n\n");
        return -1;
    }
    printf("-------------------Server start！\n");

    // 第1步：创建服务端的socket。
    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); //AF_INET 协议族,SOCK_STREAM TCPsocket类型：失败返回-1，成功返回该socket的整型数值//#include <sys/socket.h>
    if (serverSocket == -1)
    {
        perror("create socket error:\n"); //perror(s) 就是将发生错误的函数的message（也就是errno中的message）和s的信息一起打印出来。此处就是socket+socket失败后存在全局变量errno中的message
        return -1;
    }
    else
    {
        printf("1.Create Socket Successfully\n");
    }

    //第2步：把服务端用于通信的地址和端口绑定到socket上。
    //2.1 给地址信息结构体赋上传入的值
    //新建结构体指针 并进行内存清0操作
    struct sockaddr_in servaddr;          // 地址信息的数据结构。//#include <arpa/inet.h>
    memset(&servaddr, 0, sizeof(servaddr)); //将第一个参数后的第三个参数大小的内存置为第二个参数的直，就是内存清0常用函数//#include <string.h>
    //协议族赋值
    servaddr.sin_family = AF_INET; // 协议族，在socket编程中只能是AF_INET。
    //IP地址赋值 可指定IP或获取本机任意IP
    //比如一个主机三个网卡，要接收所有网卡收取的信息就要绑定三次，但是可以通过I NADDR_ANY 可以直接接收所有的网卡收到的信息
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //本机任意ip地址都能收到。 htonl 将一个32位数从主机字节顺序转换成网络字节顺序。
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); //指定ip地址。
    //端口号赋值
    servaddr.sin_port = htons(atoi(argv[1])); // 指定通信端口。atoi把字符串转换成整型数的一个函数，会跳过前面的空白字符（例如空格，tab缩进）等//#include <stdlib.h>

    //将通信信息绑定到创建的服务端socket上
    int bindResult;
    bindResult = bind(serverSocket, (struct sockaddr *)&servaddr, sizeof(servaddr)); //成功返回0，失败返回-1，错误存在errno中//获取指针长度用*servaddr
    if (bindResult == -1)
    {
        perror("bind error:\n");
        close(serverSocket); //即使失败也要关闭socket，释放资源 //#include <unistd.h>
        return -1;
    }
    else
    {
        printf("2.Bind successfully!\n");
    }

    // 第3步：把socket设置为监听模式。服务端特有的
    int listenResult;
    listenResult = listen(serverSocket, 5); //0-成功， -1-失败；第二个参数一般不超过30
    if (listenResult == -1)
    {
        perror("listen error:\n");
        close(serverSocket);
        return -1;
    }
    else
    {
        printf("3.Listen successfully!\n");
    }
    // 第4步：接受客户端的连接。
    //新建一个用于存储客户端通信信息的结构体指针
    struct sockaddr_in clientaddr;
    int socklen = sizeof(struct sockaddr_in);  
    int acceptResult;
    acceptResult = accept(serverSocket, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen); //如果客户端没连上会一直处于等待状态，又称阻塞; 第三个参数和bind的第三个参数不同,是用来存放客户端通信信息的
    if (acceptResult == -1)
    {
        printf("Server accept error:\n");
        close(serverSocket);
        return -1;
    }
    else
    {
        printf("4.Client Accept! ip:(%s)\n ---------------Communication Start---------\nWarning:If you input 'bye',this communication will end!!!\n", inet_ntoa(clientaddr.sin_addr));
    }

    char Getmessage[1024];//变量名就代表该数组首地址
    while (1)
    {
        int recvResult;
        memset(Getmessage,0,sizeof(Getmessage));//内存清零操作
        //recv函数对端关闭返回0，出错返回-1
        recvResult=recv(acceptResult,Getmessage,sizeof(Getmessage),0);// 第二个参数用来接收链接上的客户端发送的消息，第三个参数要接收信息的长度，不能超过接收实际信息的长度；第二个参数虽然是指针类型，但数组名等同于char * message；的变量名的意义
        if (recvResult<=0)
        {
            printf("recv error!\n");
            break;
        }
        else
        {
            printf("@@GetMessage：\n%s\n",Getmessage);
            if (((string)Getmessage)=="bye")
            {
                printf("---------------Communication End---------\n");
                break;
            }
            else
            {
                printf("##PlsInputMessage:\n");
                string sendMessage;
                cin>>sendMessage;
                int sendResult;
                ////与recv函数一样对端关闭返回0，出错返回-1
                sendResult=send(acceptResult,(const char *)(sendMessage.data()),sizeof(sendMessage),0);
                if (sendResult<=0)
                {
                    perror("send error:\n");
                    break;
                }
                else
                {
                    printf("---Send Successfully! Waiting the other party send a message...\n");
                    if ((string)sendMessage=="bye")
                    {
                        printf("---------------Communication End---------\n");
                        break;
                    }
                }
            }
        }
    }
    
    close(serverSocket);
    close(acceptResult);
}