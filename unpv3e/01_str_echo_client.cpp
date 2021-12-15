/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-15 10:35:40
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-15 11:05:36
 * @Description: file content
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>

int str_cli(FILE* fp, int sockfd)
{
    char sendLine[1024] = {0};
    char recvLine[1024] = {0};

    while (fgets(sendLine, 1024, fp) != nullptr)
    {
        write(sockfd, sendLine, strlen(sendLine));
        if (read(sockfd, recvLine, 1024) <= 0)
        {
            printf("read error\n");
            continue;
        }

        fputs(recvLine, stdout);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int sockfd = -1;
    uint16_t port = 9999;
    struct sockaddr_in servaddr;

    if (argc < 3)
    {
        printf("please input IP and port\n");
        return -1;
    }

    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    int result = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    str_cli(stdin, sockfd);

    return 0;
}
