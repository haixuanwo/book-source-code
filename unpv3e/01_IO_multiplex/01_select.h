/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 10:20:56
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-20 17:51:24
 * @Description: 使用select实现socket类
 */

/**
 *int select(int maxfdp1, fd_set *readset, fd_set *writeset, fd_set *except,
            const struct timeval *timeout);
 *
 * timeout：定时阻塞监控时间，3种情况
 * 1.NULL，永远等下去
 * 2.设置timeval，等待固定时间
 * 3.设置timeval里时间均为0，检查描述字后立即返回，轮询
 */

#ifndef TCP_SERVER_SELECT_H
#define TCP_SERVER_SELECT_H

extern "C" {
#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
}

#include <set>

#define MAX_LINE 1024

/**
 * @brief select 实现tcp server
 */
class TcpServer
{
public:
    TcpServer(unsigned short port)
    {
        this->port = port;
        serverFd = -1;
        maxFd = -1;
        client.clear();
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
        ret = listen(serverFd, 20); /* 默认最大128 */
        if (ret < 0)
        {
            perror("bind fail");
            return false;
        }

        //需要接收最大文件描述符
        maxFd = serverFd;

        return true;
    }

    void start()
    {
        bool ret = false;
        int readyCount = -1;
        fd_set readySet;
        struct timeval timeVal;

        FD_ZERO(&allFd);
        FD_SET(serverFd, &allFd);

        printf("server start success, listen port[%d]\n", port);

        while (1)
        {
            readySet = allFd;
            timeVal.tv_sec = 3;
            timeVal.tv_usec = 0;

            readyCount = select(maxFd+1, &readySet, nullptr, nullptr, &timeVal);
            if (readyCount < 0)
            {
                perror("select error");
                continue;
            }
            else if (0 == readyCount)
            {
                continue;
            }

            // 处理新连接的客户端
            ret = deal_client_connect(readySet);
            if (ret)
            {
                readyCount--;
            }

            // 处理客户端发来的数据
            deal_client_data(readySet, readyCount);
        }
    }

    ~TcpServer()
    {
        close(serverFd);
    }

private:
    bool deal_client_connect(fd_set readySet)
    {
        char str[16] = {0};
        int clientFd = -1;
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        if (!FD_ISSET(serverFd, &readySet))
        {
            return false;
        }

        // 是否达到集合的最大值
        if (FD_SETSIZE <= client.size())
        {
            printf("client is max setsize\n");
            return false;
        }

        //accept返回通信套接字，当前非阻塞，因为select已经发生读写事件
        clientFd = accept(serverFd, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientFd < 0)
        {
            perror("accept fail\n");
            return false;
        }

        printf("received connect from %s at PORT %d\n",
                inet_ntop(AF_INET, &clientAddr.sin_addr, str, sizeof(str)),
                ntohs(clientAddr.sin_port));

        client.insert(clientFd);

        FD_SET(clientFd, &allFd); /*添加一个新的文件描述符到监控信号集里 */

        /* select第一个参数需要 */
        for (auto fd : client)  // maxFd肯定大于等于serverFd,循环client里最大的。每次循环的原因是之前的client可能已经关闭了
        {
            if (fd > maxFd)
                maxFd = fd;
        }

        return true;
    }

    bool deal_client_data(fd_set readySet, int readyCount)
    {
        int readLen = 0;
        char buf[MAX_LINE] = {0};

        if (readyCount <= 0)
           return false;

        for (auto socketFd : client)
        {
            if (FD_ISSET(socketFd, &readySet))
			{
                readyCount--;
                // 进行读数据 不用阻塞立即读取（select已经帮忙处理阻塞环节）
                readLen = read(socketFd, buf, MAX_LINE);
                if (readLen <= 0)
				{
                    /* 无数据情况 client关闭链接，服务器端也关闭对应链接 */
                    close(socketFd);
                    FD_CLR(socketFd, &allFd);  /*解除select监控此文件描述符 */
                    client.erase(client.find(socketFd));
                    break;
                }
                printf("readLen[%d]\n", readLen);
                write(socketFd, buf, readLen);
            }

            if (readyCount <= 0)
                 break;
        }
        return true;
    }

    int serverFd;
    int maxFd;      // select用于参数
    fd_set allFd;   // 存放服务端和客户端fd
    unsigned short port;
    std::set<int> client;   // 客户端socket fd
};

#endif
