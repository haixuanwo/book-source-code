/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-15 10:35:23
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-15 12:12:05
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

/**
 * @brief 信号注册函数
 * @param signo 信号序号
 * @param func  触发信号回调函数
 * @return Sigfunc*
 */
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
    while((n = read(sockfd, buf, sizeof(1024))) > 0)
    {
        write(sockfd, buf, n);
    }

    if (n < 0 && errno == EINTR)
        goto again;
    else if (n < 0)
        printf("str echo read error\n");

    return 0;
}

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t sockLen;
    struct sockaddr_in cliaddr, servaddr;

    uint16_t port = 9999;
    if (argc > 1)
    {
        port =  atoi(argv[1]);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    int result = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (result < 0)
    {
        perror("bind fail");
        return -1;
    }

    result = listen(listenfd, 10);

    Signal(SIGCHLD, sig_chld_wait);

    while(1)
    {
        sockLen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &sockLen);
        if (connfd < 0)
        {
            perror("accept fail");
            continue;
        }

        childpid = fork();
        if (0 == childpid)
        {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }

    return 0;
}
