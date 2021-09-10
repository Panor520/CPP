#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3) //运行客户端需要知道IP地址及端口
    {
        printf("Warning:Parameter must be set\n Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n");
        return -1;
    }

    // 第1步：创建客户端的socket。
    int clientSocket;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) //socket函数返回值实际是一个文件描述符，是一个整数；失败返回-1
    {
        perror("socket erroe:\n");
        return -1;
    }
    else
    {
        printf("1.Create Socket Successfully!\n");
    }

    // 第2步：向服务器发起连接请求。
    struct hostent *h;
    h = gethostbyname(argv[1]); //gethostbyname将ip地址或域名转化为hostent结构体表达式的地址（指针地址）；失败返回NULL
    if (h == NULL)
    {
        printf("gethostbyname failed.\n");
        close(clientSocket);
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr)); //memset：将&servaddr中当前位置后sizeof(servaddr)个字节用0代替。通常为新申请的内存做初始化工作，也是对较大的结构体或数组进行清零操作的一种最快方法。
                                            //第二个参数设置为0是为了将，&servaddr开始的地址内存按sizeof(servaddr)个字节清0
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));           // 指定服务端的通信端口。
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length); //memcpy:内存拷贝函数。将h->h_addr的h->h_length个字符拷贝到&servaddr.sin_addr中。

    int connectResult;
    connectResult = connect(clientSocket, (struct sockaddr *)&servaddr, sizeof(servaddr)); //将创建的客户端socket连接至服务端，第二个参数为（struct sockaddr *）类型，第三个为第二个参数的大小；成功返回0，失败返回-1
    if (connectResult == -1)
    {
        perror("connect error");
        close(clientSocket);
        return -1;
    }
    else
    {
        printf("2.Connect Successfully! ip:(%s)\n ---------------Communication Start---------------\n Warning:If you input 'bye',this communication will end!!!\n", inet_ntoa(servaddr.sin_addr));
    }

    // char buffer[1024]; //开辟1Kb空间；字符数组，可在栈或堆上分配空间，堆上需手动管理内存。
    // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
    while (1)
    {
        int sendResult;
        string sendMessage;//使用string时无法输入空格，因为容器string遇到空格会截断数据
        printf("##PlsInputMessage:\n");
        cin >> sendMessage;
        sendResult = send(clientSocket, (const char *)sendMessage.data(), sizeof(sendMessage), 0);
        if (sendResult <= 0)
        {
            perror("send error:\n");
            break;
        }
        else
        {
            if (sendMessage=="bye")
            {
                printf("---------------Communication End---------------\n");
                break;
            }
            else
            {
                printf("---Send Successfully! Waiting the other party send a message...\n");
                string Getmessage;
                int recvResult;
                recvResult = recv(clientSocket, (char *)(Getmessage.c_str()), sizeof(Getmessage), 0);
                if (recvResult <= 0)
                {
                    printf("recv error!\n");
                    break;
                }
                else
                {
                    printf("@@GetMessage：\n%s\n", (char *)Getmessage.c_str());
                    if ((string)Getmessage.c_str()=="bye")
                    {
                        printf("---------------Communication End---------------\n");
                        break;
                    }
                }
            }
        }
    }
}
