/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-27
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#include "multi_process_server.h"

#define LISTEN_MAX 10
#define MAX_LEN 1024

Server::Server()
{
    listenfd = -1;
    bzero(&servaddr, sizeof(servaddr));
}

/**
 * @brief 绑定、监听
 * @param port 供客户端连接的端口
 * @param IP 供客户端连接的IP
 * @return true：成功，false：失败
 */
bool Server::init(unsigned int port, std::string *IP)
{
    int ret = -1;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
    {
        perror("socker error");
        return false;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    if (nullptr != IP)
    {
        inet_pton(AF_INET, IP->c_str(), &(servaddr.sin_addr.s_addr));
    }
    else
    {
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    servaddr.sin_port = htons(port);

    ret = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (ret < 0)
    {
        perror("bind error");
        return false;
    }

    ret = listen(listenfd, LISTEN_MAX);
    if (ret < 0)
    {
        perror("listen error");
        return false;
    }

    return true;
}

/**
 * @brief 接收客户端连接请求
 */
void Server::start()
{
    pid_t pid = 0;
    int connfd = -1;

    printf("start server\n");

    while (1)
    {
        connfd = accept(listenfd, (struct sockaddr*)nullptr, nullptr);
        if (connfd < 0)
        {
            perror("accept error");
            continue;
        }

        pid = fork();
        if (0 == pid)
        {
            close(listenfd);

            send_time(connfd);

            close(connfd);
            exit(0);
        }

        close(connfd);
    }
}

/**
 * @brief 给客户端发送当前时间数据
 * @param clientFd 客户端文件描述符
 * @return true：成功，false：失败
 */
bool Server::send_time(int clientFd)
{
    time_t ticks;
    int write_len = -1;
    char buff[MAX_LEN] = {0};

    if (clientFd < 0)
    {
        printf("is invailed clientFd[%d]\n", clientFd);
        return false;
    }

    ticks = time(nullptr);
    snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
    write_len = write(clientFd, buff, strlen(buff));
    if (write_len < 0)
    {
        printf("write error\n");
        return false;
    }

    return true;
}

Server::~Server()
{
    close(listenfd);
}

