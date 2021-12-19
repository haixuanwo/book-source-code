/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-19 10:01:29
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-19 11:15:08
 * @Description: file content
 */

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
#include <signal.h>
#include <sys/wait.h>

typedef void Sigfunc(int);

Sigfunc *Signal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT; // SunOS 4.x
#endif
    }
    else
    {
 #ifdef SA_RESTART
        act.sa_flags |= SA_RESTART; // SunOS 4.x
#endif
    }

    if (sigaction(signo, &act, &oact) < 0)
        return SIG_ERR;

    return oact.sa_handler;
}

void sig_chld_wait(int signo)
{
    pid_t pid;
    int stat;

    pid = wait(&stat);
    printf("child %d terminated\n", pid);

    return;
}

void sig_chld_waitpid(int signo)
{
    pid_t pid;
    int stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child %d terminated\n", pid);

    return;
}

int str_echo(int sockfd)
{
    ssize_t n;
    char buf[1024] = {0};

again:
    while((n = read(sockfd, buf, sizeof(buf))) > 0)
    {
        printf("read: %s\n", buf);

        write(sockfd, buf, n);
        printf("write back\n");

        memset(buf, 0, sizeof(buf));
    }

    if (n < 0 && errno == EINTR)
        goto again;
    else if (n < 0)
        printf("str echo read error\n");

    return 0;
}

int main(int argc, char *argv[])
{
    int tcpServerFd = -1;
    pid_t childPid;

    struct sockaddr_in tcpServerAddr;
    struct sockaddr_in tcpClientAddr;

    socklen_t sockLen = sizeof(tcpServerAddr);

    uint16_t port = 9999;
    if (argc > 1)
    {
        port =  atoi(argv[1]);
    }

    // TCP ------------------------------------------
    tcpServerFd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&tcpServerAddr, sizeof(tcpServerAddr));
    tcpServerAddr.sin_family = AF_INET;
    tcpServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    tcpServerAddr.sin_port = htons(port);

    int result = bind(tcpServerFd, (struct sockaddr*)&tcpServerAddr, sizeof(tcpServerAddr));
    if (result < 0)
    {
        perror("bind fail");
        return -1;
    }

    result = listen(tcpServerFd, 10);

    // UDP -------------------------------------------
    struct sockaddr_in udpServerAddr;
    struct sockaddr_in udpClientAddr;
    int udpServerFd = socket(AF_INET, SOCK_DGRAM, 0);
    if (udpServerFd < 0)
    {
        printf("socket fail:%s\n", strerror(errno));
        return -1;
    }

    bzero(&udpServerAddr, sizeof(udpServerAddr));
    udpServerAddr.sin_family      = AF_INET;
    udpServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    udpServerAddr.sin_port        = htons(port);

    if (bind(udpServerFd, (struct sockaddr *)(&udpServerAddr), sizeof(udpServerAddr)) < 0)
    {
        printf("bind fail:%s\n", strerror(errno));
        return -1;
    }

    printf("the tcp/udp servser run, listen[%u]\n", port);
    Signal(SIGCHLD, sig_chld_waitpid);

    int nready = -1;
    socklen_t len = -1;
    int clientFd = -1;
    fd_set readFdSet;
    FD_ZERO(&readFdSet);
    int maxFd = (tcpServerFd>udpServerFd?tcpServerFd:udpServerFd) + 1;
    while (1)
    {
        FD_SET(tcpServerFd, &readFdSet);
        FD_SET(udpServerFd, &readFdSet);

        if ((nready = select(maxFd, &readFdSet, nullptr, nullptr, nullptr)) < 0)
        {
            if (EINTR == errno)
                continue;
            else
                perror("select error");
        }

        if (FD_ISSET(tcpServerFd, &readFdSet))
        {
            len = sizeof(tcpClientAddr);
            clientFd = accept(tcpServerFd, (struct sockaddr *)&tcpClientAddr, &len);
            if (clientFd < 0)
            {
                continue;
            }

            char ipStr[16] = {0};
            printf("TCP welcom connect from %s at PORT %d\n",
                inet_ntop(AF_INET, &tcpClientAddr.sin_addr, ipStr, sizeof(ipStr)),
                ntohs(tcpClientAddr.sin_port));

            childPid = fork();
            if (0 == childPid)
            {
                close(tcpServerFd);
                str_echo(clientFd);
                exit(0);
            }
            close(clientFd);
        }

        if (FD_ISSET(udpServerFd, &readFdSet))
        {
            len = sizeof(udpServerAddr);
            char buf[1024] = {0};
            int n = recvfrom(udpServerFd, buf, 1024, 0, (struct sockaddr*)&udpClientAddr, &len);

            char ipStr[16] = {0};
            printf("UDP welcom %s at PORT %d\n",
                inet_ntop(AF_INET, &udpClientAddr.sin_addr, ipStr, sizeof(ipStr)),
                ntohs(udpClientAddr.sin_port));

            printf("recv: %s\n", buf);

            sendto(udpServerFd, buf, n, 0, (struct sockaddr*)&udpClientAddr, len);
            printf("send back\n");
        }
    }

    return 0;
}
