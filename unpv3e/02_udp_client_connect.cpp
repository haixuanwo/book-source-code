/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-19 09:26:54
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-19 10:00:08
 * @Description: file content
 */

#include<errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<sys/time.h>	/* timeval{} for select() */
#include	<time.h>		/* timespec{} for pselect() */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<sys/uio.h>		/* for iovec{} and readv/writev */
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/un.h>		/* for Unix domain sockets */
#include	<sys/select.h>
// #include	<sys/sysctl.h>
#include	<poll.h>
#include	<strings.h>
#include	<sys/ioctl.h>
// #include	<sys/filio.h>
// #include	<sys/sockio.h>
#include	<pthread.h>
// #include	<net/if_dl.h>

/**
 * @brief connect 指定对端IP和端口，不进行三次握手
 * 第二次调用：（1）指定新的对端IP和端口。（2）设置AF_UNSPEC断开套接字。
 *
 */

int main(int argc, char * argv [ ])
{
    int sockfd = -1;
    uint16_t port = 9999;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    socklen_t addr_len = sizeof(serverAddr);

    if (argc < 3)
    {
        printf("please input IP and port\n");
        return -1;
    }

    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket fail\n");
        return -1;
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family      = AF_INET;
    serverAddr.sin_port        = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    // inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("connect fail");
        return -1;
    }

    socklen_t len = sizeof(clientAddr);
    getsockname(sockfd, (struct sockaddr *)&clientAddr, &len);

    char ip[16]={0};
    printf("local address %s\n", inet_ntop(AF_INET, &clientAddr.sin_addr, ip, sizeof(ip)));
    // printf("local address %s\n", sock_ntop((struct sockaddr *)&clientAddr, len));

    close(sockfd);
    return 0;
}
