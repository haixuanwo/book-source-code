/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-01-06
 * @brief tcp通信客户端
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 51690
#define IP "127.0.0.1"

int main(int argc, char *argv[])
{
	int len = -1;
    int client_fd = -1;
	char buf[MAX_LINE]={0};
	struct sockaddr_in s_addr;
    char hello_msg[MAX_LINE] = {0};

    if (argc < 2)
    {
        printf("please input send msg\n");
        return -1;
    }

	// 创建套接字
	bzero(&s_addr, sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr = inet_addr(IP);
	s_addr.sin_port = htons(PORT);
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (client_fd < 0)
	{
	    perror("socket fail");
		return -1;
	}

	// 连接
	if (connect(client_fd, (struct sockaddr *)(&s_addr), sizeof(s_addr)) < 0)
	{
        perror("connect fail");
		return -1;
	}

    snprintf(hello_msg, sizeof(hello_msg), "I am client %s", argv[1]);

    while(1)
    {
        len = write(client_fd, hello_msg, strlen(hello_msg));
        if(len < 0)
        {
            perror("write fail\n");
			return -1;
		}

        memset(buf, 0, sizeof(buf));
        len = read(client_fd, buf, sizeof(buf) - 1);
        if (len > 0)
        {
            printf("read:%s\n", buf);
        }

		sleep(3);
    }

    return 0;
}

