/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-18 09:48:30
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-18 10:31:57
 * @Description: udp通信服务端
 */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 9999
#define MAX_LINE 1024

void dg_echo(int sockfd, struct sockaddr* clientAddr, socklen_t clientAddrLen)
{
    char recv_buf[MAX_LINE] = {0};

    while(1)
    {
        memset(recv_buf, 0, sizeof(recv_buf));
        if (recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, clientAddr, &clientAddrLen) < 0)
        {
            perror("recvfrom fail");
            continue;
        }
        printf("recv:%s\n", recv_buf);

        if (sendto(sockfd, recv_buf, strlen(recv_buf), 0, clientAddr, clientAddrLen) < 0)
        {
            perror("sendto fail");
            continue;
        }
    }
}

int main(int argc, char * argv [ ])
{
    int sockfd = -1;
    uint16_t port = PORT;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    if (argc > 1)
    {
        port = atoi(argv[1]);
    }

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("socket fail:%s\n", strerror(errno));
        return -1;
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family      = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port        = htons(port);

    if (bind(sockfd, (struct sockaddr *)(&serverAddr), sizeof(serverAddr)) < 0)
    {
        printf("bind fail:%s\n", strerror(errno));
        return -1;
    }

    dg_echo(sockfd, (struct sockaddr *)(&clientAddr), sizeof(clientAddr));

    close(sockfd);
}
