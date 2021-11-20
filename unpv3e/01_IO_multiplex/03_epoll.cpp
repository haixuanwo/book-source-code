/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 17:54:29
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-20 18:05:18
 * @Description: file content
 */

/******************************************************************************
* Copyright (C) 2020, 协议森林.
*
* File Name:    tcpepoll.c
* Author:       协议森林
* Date:         2020-12-22
* Description:
-------------------------------------------------------------------------------
功能汇总:
        1)关于epoll的用法
        2)服务端代码

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAXEVENTS 100


// 初始化服务端的监听端口。
static int CreateServer(int port)
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock < 0)
    {
        printf("socket() failed.\n");
        return -1;
    }

    int opt = 1;
    unsigned int len = sizeof(opt);
    //一个端口释放后会等待两分钟之后才能再被使用，SO_REUSEADDR是让端口释放后立即就可以被再次使用
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, len);
    setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &opt, len);

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if(bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
    {
        printf("bind() failed.\n");
        close(sock);
        return -1;
    }

    if(listen(sock, 5) != 0)//最大可连接为5
    {
        printf("listen() failed.\n");
        close(sock);
        return -1;
    }

    return sock;
}

// 把socket设置为非阻塞的方式。
static int setnonblocking(int sockfd)
{
    if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK) == -1)
    {
        return -1;
    }

    return 0;
}

int main(int argc,char *argv[])
{
    //校验输入参数完整性
    if(argc != 2)
    {
        printf("usage:./tcpepoll port,for example:./tcpepoll 8080.\n");
        return -1;
    }

    // 建立监听的socket
    int ListenSock = CreateServer(atoi(argv[1]));
    printf("ListenSock=%d\n", ListenSock);
    if (ListenSock < 0)
    {
        printf("CreateServer() failed.\n");
        return -1;
    }

    int   EpollFd = 0;
    char  Buffer[1024];
    memset(Buffer, 0, sizeof(Buffer));

    //epoll创建一个描述符,max_size标识监听数目最大数
    EpollFd = epoll_create(1);

    // 添加监听描述符事件
    struct epoll_event ev;
    ev.data.fd = ListenSock;
    ev.events = EPOLLIN;
    epoll_ctl(EpollFd, EPOLL_CTL_ADD, ListenSock, &ev);

    while (1)
    {
        //存放有事件发生的结构数组
        struct epoll_event events[MAXEVENTS];

        //等待监视的socket有事件发生
        int infds = epoll_wait(EpollFd, events, MAXEVENTS, -1);
        // printf("epoll_wait infds=%d\n",infds);

        // 返回失败。
        if (infds < 0)
        {
            printf("epoll_wait() failed.\n");
            break;
        }

        // 超时。
        if (infds == 0)
        {
            printf("epoll_wait() timeout.\n"); continue;
        }

        // 遍历有事件发生的结构数组。
        for (int ii = 0; ii < infds; ii++)
        {
             printf("infds[%d]. ListenSock[%d].events[%d].data.fd[%d]\n",infds,ListenSock,ii,events[ii].data.fd);
            if((events[ii].data.fd == ListenSock) &&(events[ii].events & EPOLLIN))
            {
                // 如果发生事件的是ListenSock，表示有新的客户端连上来。
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                int clientsock = accept(ListenSock, (struct sockaddr*)&client, &len);
                printf("~~~~~~clientsock[%d]\n",clientsock);
                if (clientsock < 0)
                {
                    printf("accept() failed.\n");
                    continue;
                }

                // 把新的客户端添加到epoll中。
                memset(&ev, 0, sizeof(struct epoll_event));
                ev.data.fd = clientsock;
                ev.events = EPOLLIN;
                epoll_ctl(EpollFd, EPOLL_CTL_ADD, clientsock, &ev);

                printf ("client(socket=%d) connected ok.\n",clientsock);

                continue;
            }
            else if (events[ii].events & EPOLLIN)
            {
                // 客户端有数据过来或客户端的socket连接被断开。
                char Buffer[1024];
                memset(Buffer, 0, sizeof(Buffer));

                // 读取客户端的数据。
                ssize_t isize = read(events[ii].data.fd, Buffer, sizeof(Buffer));

                // 发生了错误或socket被对方关闭。
                if (isize <=0)
                {
                    printf("client(eventfd=%d) disconnected.\n",events[ii].data.fd);

                    // 把已断开的客户端从epoll中删除。
                    memset(&ev,0,sizeof(struct epoll_event));
                    ev.events = EPOLLIN;
                    ev.data.fd = events[ii].data.fd;
                    epoll_ctl(EpollFd, EPOLL_CTL_DEL, events[ii].data.fd, &ev);
                    close(events[ii].data.fd);
                    continue;
                }

                printf("recv(eventfd=%d,size=%ld):%s\n",events[ii].data.fd, isize, Buffer);

                //把收到的报文发回给客户端。
                write(events[ii].data.fd,Buffer,strlen(Buffer));
            }//end else if (events[ii].events & EPOLLIN)
            else
            {
                printf("this is nothing.\n");
            }
        }
    }//end while(1)

    close(EpollFd);

    return 0;
}
