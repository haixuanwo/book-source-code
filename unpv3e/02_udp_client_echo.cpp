/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-18 10:02:46
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-18 10:17:11
 * @Description: udp通信客户端
 */

#include<errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 9999
#define MAX_LINE 1024

int dg_cli(FILE* fp, int sockfd, struct sockaddr *serverAddr, socklen_t serverAddrLen)
{
    char sendBuf[MAX_LINE] = {0};
    char recvBuf[MAX_LINE + 1] = {0};

    while (fgets(sendBuf, MAX_LINE, fp))
    {
        sendto(sockfd, sendBuf, strlen(sendBuf), 0, serverAddr, serverAddrLen);
        if (recvfrom(sockfd, recvBuf, MAX_LINE, 0, nullptr, nullptr) > 0)
        {
            printf("%s\n", recvBuf);
        }
    }
    return 0;
}

int main(int argc, char * argv [ ])
{
    int sockfd = -1;
    uint16_t port = PORT;

    struct sockaddr_in serverAddr;
    socklen_t addr_len = sizeof(serverAddr);

    if (argc < 3)
    {
        printf("please input IP and port\n");
        return -1;
    }

    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket fail\n");
        return -1;
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family      = AF_INET;
    serverAddr.sin_port        = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    // inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    dg_cli(stdin, sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    close(sockfd);
    return 0;
}
