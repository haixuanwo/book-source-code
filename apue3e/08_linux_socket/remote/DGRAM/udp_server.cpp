/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief udp通信服务端
 */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

#define PORT 51690
#define MAX_LINE 1024

int main(int argc, char * argv [ ])
{
    int sockfd = -1;
    char recv_buf[MAX_LINE] = {0};
    struct sockaddr_in servaddr;
    struct sockaddr_in clientaddr;
    socklen_t addr_len = sizeof(servaddr);
    char reply_message[MAX_LINE] = {"I am server"};

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("socket fail:%s\n", strerror(errno));
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)(&servaddr), sizeof(servaddr)) < 0)
    {
        printf("bind fail:%s\n", strerror(errno));
        return -1;
    }

    while(1)
    {
        memset(recv_buf, 0, sizeof(recv_buf));
        if (recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&clientaddr, &addr_len) < 0)
        {
            perror("recvfrom fail");
            return -1;
        }
        printf("recv:%s\n", recv_buf);

        if (sendto(sockfd, reply_message, strlen(reply_message), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr)) < 0)
        {
            perror("sendto fail");
            return -1;
        }
    }

    close(sockfd);
}

