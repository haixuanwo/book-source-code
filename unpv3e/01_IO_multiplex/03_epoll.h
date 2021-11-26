/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 17:54:17
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-26 20:05:09
 * @Description: file content
 */

/**
 * 获取事件的时候，它无须遍历整个被侦听的描述符集，只要遍历那些被内核IO事件异步唤醒而加入Ready队列的描述符集合
 * epoll将这两个操作分开，先用epoll_ctl维护等待队列，再调用epoll_wait阻塞进程（解耦）。显而易见的，效率就能得到提升
 * 内核维护一个“就绪列表”，引用收到数据的socket，就能避免遍历
 */
#ifndef TCP_SERVER_EPOLL_H
#define TCP_SERVER_EPOLL_H

extern "C" {
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
}

#define MAX_EVENTS 100
#define CLIENT_SIZE 100

/**
 * @brief epoll 实现tcp server
 */
class TcpServer
{
public:
    TcpServer(unsigned short port)
    {
        this->port = port;
        serverFd = -1;
    }

    /**
     * @brief 设置为非阻塞
     * @param fd scoket fd
     * @return true
     */
    bool setNonblock(int fd)
    {
        int mode = 0;
        mode = fcntl(fd, F_GETFL);
        mode |= O_NONBLOCK;
        fcntl(fd, F_SETFL, mode);

        return true;
    }

    /**
     * @brief 创建socket、bind、listen
     * @return true
     * @return false
     */
    bool init()
    {
        int ret = -1;
        struct sockaddr_in serverAddr;

        // 创建套接字
        serverFd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverFd < 0)
        {
            perror("socket fail");
            return false;
        }

        // 绑定
        bzero(&serverAddr, sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serverAddr.sin_port = htons(port);
        ret = bind(serverFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
        if (ret < 0)
        {
            perror("bind fail");
            return false;
        }

        // 监听
        ret = listen(serverFd, CLIENT_SIZE); /* 默认最大128 */
        if (ret < 0)
        {
            perror("bind fail");
            return false;
        }

        return true;
    }

    void start()
    {
        int   epollFd = 0;
        char  buffer[1024] = {0};
        int eventCount = 0;
        //存放有事件发生的结构数组
        struct epoll_event events[MAX_EVENTS];

        //epoll创建一个描述符,max_size标识监听数目最大数
        epollFd = epoll_create(1);

        // 添加监听描述符事件
        struct epoll_event epollEvent;
        epollEvent.data.fd = serverFd;
        epollEvent.events = EPOLLIN;
        epoll_ctl(epollFd, EPOLL_CTL_ADD, serverFd, &epollEvent);

        while (1)
        {
            //等待监视的socket有事件发生
            eventCount = epoll_wait(epollFd, events, MAX_EVENTS, -1);
            if (eventCount < 0)
            {
                printf("epoll_wait() failed.\n");
                break;
            }
            else if (0 == eventCount)
            {
                printf("epoll_wait() timeout.\n");
                continue;
            }

            for (int i = 0; i < eventCount; i++)
            {
                printf("infds[%d]. ListenSock[%d].events[%d].data.fd[%d]\n",
                        eventCount, serverFd, i, events[i].data.fd);

                if ((events[i].data.fd == serverFd) && (events[i].events & EPOLLIN))
                {
                    // 如果发生事件的是ListenSock，表示有新的客户端连上来。
                    struct sockaddr_in client;
                    socklen_t len = sizeof(client);
                    int clientFd = accept(serverFd, (struct sockaddr*)&client, &len);
                    printf("~~~~~~clientsock[%d]\n",clientFd);
                    if (clientFd < 0)
                    {
                        printf("accept() failed.\n");
                        continue;
                    }

                    // 把新的客户端添加到epoll中。
                    memset(&epollEvent, 0, sizeof(struct epoll_event));
                    epollEvent.data.fd = clientFd;
                    epollEvent.events = EPOLLIN;
                    epoll_ctl(epollFd, EPOLL_CTL_ADD, clientFd, &epollEvent);

                    printf ("client(socket=%d) connected ok.\n",clientFd);

                    continue;
                }
                else if (events[i].events & EPOLLIN)
                {
                    // 客户端有数据过来或客户端的socket连接被断开。
                    char Buffer[1024];
                    memset(Buffer, 0, sizeof(Buffer));

                    // 读取客户端的数据。
                    ssize_t isize = read(events[i].data.fd, Buffer, sizeof(Buffer));

                    // 发生了错误或socket被对方关闭。
                    if (isize <=0)
                    {
                        printf("client(eventfd=%d) disconnected.\n",events[i].data.fd);

                        // 把已断开的客户端从epoll中删除。
                        memset(&epollEvent,0,sizeof(struct epoll_event));
                        epollEvent.events = EPOLLIN;
                        epollEvent.data.fd = events[i].data.fd;
                        epoll_ctl(epollFd, EPOLL_CTL_DEL, events[i].data.fd, &epollEvent);
                        close(events[i].data.fd);
                        continue;
                    }

                    printf("recv(eventfd=%d,size=%ld):%s\n",events[i].data.fd, isize, Buffer);

                    //把收到的报文发回给客户端。
                    write(events[i].data.fd,Buffer,strlen(Buffer));
                }//end else if (events[ii].events & EPOLLIN)
            }
        }//end while(1)

        close(epollFd);
    }

    ~TcpServer()
    {
        close(serverFd);
    }

private:
    int serverFd;
    unsigned short port;
};

#endif
