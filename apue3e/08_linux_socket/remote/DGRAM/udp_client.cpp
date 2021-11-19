/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief udp通信客户端
 */
#include<errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 51690
#define MAX_LINE 1024

int main(int argc, char * argv [ ])
{
    int sockfd = -1;
    char buf[MAX_LINE] = {0};
    struct sockaddr_in servaddr;
    socklen_t addr_len = sizeof(servaddr);

    if (argc < 2)
    {
        printf("please input send msg\n");
        return -1;
    }

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("socket fail:%s\n", strerror(errno));
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_port        = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while(1)
    {
        sendto(sockfd, argv[1], strlen(argv[1]), 0, (struct sockaddr *)(&servaddr), sizeof(servaddr));

        memset(buf, 0, sizeof(buf));
        if (recvfrom(sockfd, buf, MAX_LINE, 0, (struct sockaddr*)&servaddr, &addr_len) > 0)
        {
            printf("%s\n", buf);
        }

        sleep(3);
    }

    close(sockfd);
    return 0;
}

