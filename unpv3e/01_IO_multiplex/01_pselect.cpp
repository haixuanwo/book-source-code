/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-16 09:57:26
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-16 10:17:07
 * @Description: file content
 */

/**
 * 比select多了信号屏蔽功能
 * int pselect(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
 *              const struct timespec *timeout, const sigset_t *sigmask);
 */

#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

int sigint_event = 0;

void sigint_sig_handler(int s)
{
    sigint_event++;
    signal(SIGINT, sigint_sig_handler);
}

int main()
{
    int r = 0;
    fd_set rd;
    sigset_t sigmask, original_sigmask;

    FD_ZERO(&rd);
    FD_SET(0, &rd);

    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGINT); // 屏蔽了ctrl+c触发的SIGINT信号
    sigprocmask(SIG_BLOCK, &sigmask, &original_sigmask);
    signal(SIGINT, sigint_sig_handler);

    while(1)
    {
        for (; sigint_event > 0; sigint_event--)
        {
            printf("sigint_event[%d]\n", sigint_event);
        }

        r = pselect(1, &rd, NULL, NULL, NULL, &original_sigmask);
        if (-1 == r)
        {
            perror("pselect fail");
        }
        else if (r)
        {
            printf("Data is available now\n");
        }
        else
        {
            printf("No data with in five seconds\n");
        }
        sleep(1);
    }

    return 0;
}

