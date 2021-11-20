/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 15:56:43
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-20 17:49:46
 * @Description: poll
 */

/**
 *
 * select缺点：
 * 1.每次调用select()，都需要把fd集合从用户态拷贝到内核态，这个开销在fd很多时会很大，
 *   同时每次调用 select() 都需要在内核遍历传递进来的所有 fd，这个开销在 fd 很多时也很大。
 * 2.单个进程能够监视的文件描述符的数量存在最大限制，在 Linux 上一般为 1024，
 *   可以通过修改宏定义甚至重新编译内核的方式提升这一限制，但是这样也会造成效率的降低
 *
 * poll:
 *  poll() 没有最大文件描述符数量的限制
 *  包含大量文件描述符的数组被整体复制于用户态和内核的地址空间之间
 *
 * struct pollfd {
 *  int fd;        //文件描述符
 *  short events;  //要求查询的事件掩码
 *  short revents; //返回的事件掩码
 * };
 * int poll(struct pollfd *ufds, unsigned int nfds, int timeout);
 * timeout为负数表示无线等待，timeout为0表示调用后立即返回。
 * 执行结果：为0表示超时前没有任何事件发生；-1表示失败；成功则返回结构体中revents不为0的文件描述符个数
 */

#ifndef TCP_SERVER_POLL_H
#define TCP_SERVER_POLL_H

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
}

#include <map>
#include <string>

#define MAX_LINE 1024
#define CLIENT_SIZE 20
#define TIMEOUT_MS  3000 // 单位ms
#define BUF_SIZE 1024

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
    }

    /**
     * @brief 设置为非阻塞
     * @param fd scoket fd
     * @return int
     */
    bool setnoblock(int fd)
    {
        int oldopt = fcntl(fd, F_GETFL);
        int newopt = oldopt | O_NONBLOCK;
        fcntl(fd, F_SETFL, newopt);
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
        struct pollfd fds[CLIENT_SIZE];
        std::map<int, std::string> mapdata;
        fds[0].fd = serverFd;
        fds[0].events = POLLIN | POLLERR;//监听 in和err事件
        fds[0].revents = 0;
        int conncount = 0;

        while (1)
        {
            int ret = poll(fds, conncount + 1, TIMEOUT_MS);
            if (ret < 0)
            {
                fprintf(stderr, "poll: %d, %s\n", errno, strerror(errno));
                exit(1);
            }

            for (int i = 0; i < conncount + 1; i++)
            {
                // 客户端关闭，或者错误。错误的原因是由于客户端关闭导致的，这里一并处理
                if ((fds[i].revents & POLLRDHUP) || (fds[i].revents & POLLERR))
                {
                    int fd = fds[i].fd;
                    fds[i] = fds[conncount];
                    i--;
                    conncount--;
                    mapdata.erase(fd);
                    close(fd);
                    printf("delete connection: %d\n", fd);
                }
                // 新的连接
                else if ((fds[i].fd == serverFd) && (fds[i].revents & POLLIN))
                {
                    struct sockaddr_in client;
                    socklen_t lenaddr = sizeof(client);
                    int conn = -1;

                    if (-1 == (conn = accept(serverFd, (struct sockaddr*)&client, &lenaddr)))
                    {
                        fprintf(stderr, "accept: %d, %s\n", errno, strerror(errno));
                        exit(1);
                    }
                    printf("get connection %d from %s:%d\n", conn, inet_ntoa(client.sin_addr), client.sin_port);
                    conncount++;
                    setnoblock(conn);
                    fds[conncount].fd = conn;
                    fds[conncount].events = POLLIN | POLLRDHUP | POLLERR;
                    fds[conncount].revents = 0;
                }
                // 有可读数据
                else if (fds[i].revents & POLLIN)
                {
                    char buf[BUF_SIZE] = {0};

                    int lenrecv = recv(fds[i].fd, buf, BUF_SIZE-1, 0);
                    if (lenrecv > 0)
                    {
                        mapdata[fds[i].fd] = buf;
                        fds[i].events &= (~POLLIN);
                        fds[i].events |= POLLOUT;
                        printf("recv buf:%s\n", buf);
                    }
                    else if (lenrecv == 0)
                    {
                        printf("------- client %d exit (not print) --------\n", fds[i].fd);
                    }
                }
                // 可写数据
                else if (fds[i].revents & POLLOUT)
                {
                    if (send(fds[i].fd, mapdata[fds[i].fd].c_str(), mapdata[fds[i].fd].size(), 0) < 0)
                    {
                        if (ECONNRESET == errno)
                        {
                            continue;
                        }
                        fprintf(stderr, "send: %d, %s\n", errno, strerror(errno));
                        exit(1);
                    }
                    fds[i].events &= (~POLLOUT);
                    fds[i].events |= POLLIN;
                }
            }
        }
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
