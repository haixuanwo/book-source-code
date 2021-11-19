/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief tcp通信服务端
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

#define PORT 51690
#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    pid_t pid;
	int len = -1;
    int client_fd = -1;
    int server_fd = -1;
    char ip[20] = {0};
	char buf[MAX_LINE] = {0};
    char reply_msg[] = {"I am server"};
	struct sockaddr_in s_addr,c_addr;
	int sizeSockaddr = sizeof(struct sockaddr_in );

    // 创建套接字
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd < 0)
	{
        perror("socket fail");
		return -1;
	}

    // 绑定
	bzero(&s_addr, sizeSockaddr);
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr *)(&s_addr), sizeof(struct sockaddr)) < 0)
	{
        perror("bind fail");
		return -1;
	}

	// 监听
	if (listen(server_fd, 10) < 0)
	{
	    perror("listen fail");
		return -1;
	}

    signal(SIGCHLD, SIG_IGN);  // 忽略子进程信号，子进程退出时由init进程回收资源

	while(1)
	{
        client_fd = accept(server_fd, (struct sockaddr *)(&c_addr), (socklen_t*)&sizeSockaddr);
        if(client_fd < 0)
        {
            perror("accept fail");
		    return -1;
    	}

        memset(ip, 0, sizeof(ip));
        inet_ntop(AF_INET, (void *)&c_addr.sin_addr.s_addr, ip, 16);
        printf("welcom IP:[%s] port:[%d]\n", ip, ntohs(c_addr.sin_port));

        pid = fork();
        if (0 == pid) // 子进程
        {
            while(1)
            {
                memset(buf, 0, sizeof(buf));
                len = read(client_fd, buf, sizeof(buf));
                if(len < 0)
                {
                    perror("read fail");
    		        return -1;
                }
                printf("read:%s\n", buf);

                write(client_fd, reply_msg, strlen(reply_msg));
            }
        }
        else
        {
            close(client_fd);
        }
    }

    return 0;
}

