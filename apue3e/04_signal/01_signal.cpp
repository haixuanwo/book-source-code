/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-18 18:54:00
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 19:21:18
 * @Description: signal函数
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_usr(int signo)
{
    if (SIGUSR1 == signo)
        printf("I'm usr1\n");
    else if (SIGUSR2 == signo)
        printf("I'm usr2\n");
    else
        printf("I'm signal[%d]\n", signo);
}

/**
 * @brief 接收用户信号
 * kill -USR1 PID
 * kill -USR2 PID
 * kill pid  # 发送SIGTERM
 */
int main()
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        printf("can't catch SIGUSR1\n");

    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        printf("can't catch SIGUSR2\n");

    for (;;)
    {
        sleep(3);

        // 给自己发信号
        raise(SIGUSR1);
        raise(SIGUSR2);

        // 给指定的进程发信号
        kill(getpid(), SIGUSR1);
        kill(getpid(), SIGUSR2);

        // 设置秒数后给自己发SIGALRM
        alarm(3);

        // 进程挂起，直到捕捉到信号
        pause();
    }

    return 0;
}
