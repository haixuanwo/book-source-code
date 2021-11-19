/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief tcp域通信客户端
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

#define   MAX_LINE  1024
#define PATH_LISTEN "path.listen"

int main(int argc, const char *argv[])
{
    int sockfd = -1;
    struct sockaddr_un  serveraddr, clientaddr;
    char buf[MAX_LINE] = {0};

    if (argc < 2)
    {
        printf("please input send msg\n");
        return -1;
    }

    if((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    {
        perror("socket fail");
        return -1;
    }

    serveraddr.sun_family = AF_UNIX;
    strcpy(serveraddr.sun_path, PATH_LISTEN);

    if(connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("connect fail");
        return -1;
    }

    while(1)
    {
        if(send(sockfd, argv[1], strlen(argv[1]), 0) < 0)
        {
            perror("send fail");
            return -1;
        }

        memset(buf, 0, sizeof(buf));
        if(recv(sockfd, buf, MAX_LINE, 0) < 0)
        {
            perror("recv fail");
            return -1;
        }
        printf("recv:%s\n", buf);
        sleep(3);
    }

    close(sockfd);
    return 0;
}

