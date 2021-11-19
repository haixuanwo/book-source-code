/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief udp域通信服务端
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

#define   MAX_LINE  128
#define PATH_LISTEN "path.listen"

// AF_LOCAL和AF_UNIX的数值都为1，即含义是一样的都表示域通信协议
//#define FAMILY AF_UNIX
#define FAMILY AF_LOCAL

int main(int argc, const char *argv[])
{
    int sockfd;
    struct sockaddr_un serveraddr;
    struct sockaddr_un clientaddr;
    socklen_t addrlen = sizeof(clientaddr);
    char buf[MAX_LINE] = {};
    char reply_message[MAX_LINE] = {0};

    if((sockfd = socket(FAMILY, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket fail");
        return -1;
    }

    unlink(PATH_LISTEN);
    serveraddr.sun_family = FAMILY;
    strcpy(serveraddr.sun_path, PATH_LISTEN);

    if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("bind fail");
        return -1;
    }

    while(1)
    {
        memset(buf, 0, sizeof(buf));
        if(recvfrom(sockfd, buf, MAX_LINE, 0, (struct sockaddr*)&clientaddr, &addrlen) < 0)
        {
            perror("recvfrom fail");
            return -1;
        }
        printf("From [%s] --> %s\n", clientaddr.sun_path, buf);

        snprintf(reply_message, sizeof(reply_message), "%s: I am server", clientaddr.sun_path);
        if(sendto(sockfd, reply_message, strlen(reply_message), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr)) < 0)
        {
            perror("sendto fail");
            return -1;
        }
    }

    close(sockfd);
    return 0;
}

