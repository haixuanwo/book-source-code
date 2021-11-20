/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 14:40:20
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-20 15:47:53
 * @Description: file content
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

#ifndef TCP_SERVER_THREAD_H
#define TCP_SERVER_THREAD_H

extern "C" {
#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
}

#include <set>

#define MAX_LINE 1024

class Mutex
{
public:
    Mutex()
    {
        pthread_mutex_init(&mutex, nullptr);
    }

    void lock()
    {
        pthread_mutex_lock(&mutex);
        // pthread_mutex_trylock 加锁失败直接退出
        // pthread_mutex_timedlock 设定时间内还未加锁成功则退出
    }

    void unlock()
    {
        pthread_mutex_unlock(&mutex);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(&mutex);
    }

private:
    pthread_mutex_t mutex;
};

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

        return true;
    }

    bool start()
    {
        char str[16] = {0};
        int clientFd = -1;
        pthread_t thId;
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        printf("server start success, listen port[%d]\n", port);

        int ret = pthread_create(&thId, nullptr, TcpServer::deal_client_data, nullptr);
        if (ret < 0)
        {
            perror("pthread create fail\n");
            return false;
        }

        FD_ZERO(&clientFdSet);
        while (1)
        {
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

            // 是否达到集合的最大值
            if (FD_SETSIZE <= client.size())
            {
                printf("client is max setsize\n");
                close(clientFd);
                continue;
            }

            //mutex.lock();

            client.insert(clientFd);            // 保存客户端socket fd
            FD_SET(clientFd, &clientFdSet);     // 添加一个新的文件描述符到监控信号集里

            // 每次循环的原因是之前的client可能已经关闭了
            for (auto fd : client)
            {
                if (fd > maxFd)
                    maxFd = fd;
            }

            //mutex.unlock();
        }
    }

    ~TcpServer()
    {
        close(serverFd);
    }

private:

    static void *deal_client_data(void *ptr)
    {
        bool ret = false;
        fd_set readySet;
        struct timeval timeVal;
        int readLen = 0;
        char buf[MAX_LINE] = {0};
        int readyCount = -1;

        while (1)
        {
            timeVal.tv_sec = 3;
            timeVal.tv_usec = 0;

            mutex.lock();
            readySet = clientFdSet;
            readyCount = select(maxFd+1, &readySet, NULL, NULL, &timeVal);
            mutex.unlock();

            if (readyCount < 0)
            {
                perror("select error");
                continue;
            }
            else if (0 == readyCount)
            {
                continue;
            }

            mutex.lock();
            for (int socketFd : client)
            {
                if (FD_ISSET(socketFd, &readySet))
                {
                    if (readyCount <= 0)
                        break;

                    readyCount--;

                    // 进行读数据不用阻塞立即读取（select已经帮忙处理阻塞环节）
                    readLen = read(socketFd, buf, MAX_LINE);
                    if (readLen <= 0)
                    {
                        /* 无数据情况 client关闭链接，服务器端也关闭对应链接 */
                        close(socketFd);
                        FD_CLR(socketFd, &clientFdSet);  /*解除select监控此文件描述符 */
                        client.erase(client.find(socketFd));
                        break;
                    }
                    printf("readLen[%d]\n", readLen);
                    write(socketFd, buf, readLen);
                }
            }
            mutex.unlock();
        }
        return nullptr;
    }

    int serverFd;                  // 服务端socket fd
    unsigned short port;           // listen端口
    static int maxFd;              // 用于select参数
    static fd_set clientFdSet;     // 客户端fd
    static std::set<int> client;   // 客户端socket fd
    static Mutex mutex;
};

int TcpServer::maxFd = -1;         // 用于select参数
fd_set TcpServer::clientFdSet;     // 客户端fd
std::set<int> TcpServer::client;   // 客户端socket fd
Mutex TcpServer::mutex;

#endif
