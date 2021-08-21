
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

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd = -1;
    int n = -1;
    char recvline[MAX_LINE + 1] = {0};
    struct sockaddr_in servaddr;

    if (argc != 3)
    {
        printf("please input IP and port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("socket fail\n");
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        printf("inet_pton error\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))<0)
    {
        printf("connect error\n");
        return -1;
    }

    while (1)
    {
        n = read(sockfd, recvline, MAX_LINE);
        if (n > 0)
        {
            recvline[n] = 0;
            if (fputs(recvline, stdout) == EOF)
                printf("fputs error\n");

            break;
        }
        sleep(1);
    }

    if (n < 0)
        printf("read error\n");

    return 0;
}

