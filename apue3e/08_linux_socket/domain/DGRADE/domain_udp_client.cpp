/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief udp域通信客户端
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

#define   MAX_LINE  1024
#define PATH_LISTEN "path.listen"

// AF_LOCAL和AF_UNIX的数值都为1，即含义是一样的都表示域通信协议
//#define FAMILY AF_UNIX
#define FAMILY AF_LOCAL

int main(int argc, const char *argv[])
{
    int sockfd = -1;
    struct sockaddr_un serveraddr;
    struct sockaddr_un clientaddr;
    socklen_t addrlen = sizeof(clientaddr);
    char buf[MAX_LINE] = {0};

    if (argc < 3)
    {
        printf("please input client listen and send str\n");
        return -1;
    }

    if((sockfd = socket(FAMILY, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket fail");
        return -1;
    }

    // 关联发送信息到服务端
    serveraddr.sun_family = FAMILY;
    strcpy(serveraddr.sun_path, PATH_LISTEN);

    // 关联接收服务端信息
    unlink(argv[1]);
    clientaddr.sun_family = FAMILY;
    strcpy(clientaddr.sun_path, argv[1]);

    if(bind(sockfd, (struct sockaddr*)&clientaddr, sizeof(clientaddr)) < 0)
    {
        perror("bind fail");
        return -1;
    }

    while(1)
    {
        if(sendto(sockfd, argv[2], strlen(argv[2]), 0, (struct sockaddr *)&serveraddr, addrlen) < 0)
        {
            perror("sendto fail");
            return -1;
        }

        if(recvfrom(sockfd, buf, MAX_LINE, 0, (struct sockaddr *)&serveraddr, &addrlen) < 0)
        {
            perror("recvfrom fail");
            return -1;
        }

        printf("%s\n", buf);
        sleep(3);
    }

    close(sockfd);
    return 0;
}


