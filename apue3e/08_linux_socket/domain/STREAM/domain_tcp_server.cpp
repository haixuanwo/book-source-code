/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief tcp域通信服务端
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
#include <signal.h>

#define  MAX_LINE  128
#define PATH_LISTEN "path.listen"

int main(int argc, const char *argv[])
{
    pid_t pid;
    int sockfd = -1;
    int confd  = -1;
    struct sockaddr_un  serveraddr, clientaddr;
    char buf[MAX_LINE] = {0};
    char reply_msg[MAX_LINE] = {0};

    if((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    {
        perror("socket fail");
        return -1;
    }

    unlink(PATH_LISTEN);
    serveraddr.sun_family = AF_UNIX;
    strcpy(serveraddr.sun_path, PATH_LISTEN);
    if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("bind fail");
        return -1;
    }

    if(listen(sockfd, 10) < 0)
    {
        perror("listen fail");
        return -1;
    }

    socklen_t addrlen = sizeof(struct sockaddr);

    signal(SIGCHLD ,SIG_IGN);  // 忽略子进程信号，子进程退出时由init进程回收资源

    while(1)
    {
        if((confd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen)) < 0)
        {
            perror("accept fail");
            return -1;
        }

        pid = fork();
        if (0 == pid) // 子进程
        {
            while(1)
            {
                if(recv(confd, buf, MAX_LINE, 0) < 0)
                {
                    perror("recv fail");
                    return -1;
                }
                printf("recv:%s\n", buf);

                snprintf(reply_msg, sizeof(reply_msg), "%s:I am server", clientaddr.sun_path);
                if(send(confd, reply_msg, strlen(reply_msg), 0) < 0)
                {
                    perror("send fail");
                    return -1;
                }
            }
        }
        else
        {
            close(confd);
        }
    }

    close(sockfd);

    return 0;
}


