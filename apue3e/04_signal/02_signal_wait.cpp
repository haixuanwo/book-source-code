/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-18 19:06:19
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 19:13:17
 * @Description: signal和wait函数
 */

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_cld(int signo)
{
    pid_t pid;
    int status;

    printf("SIGCLD received\n");

    if (signal(SIGCLD, sig_cld) == SIG_ERR)
        printf("signal error\n");

    if ((pid = wait(&status)) < 0)
        printf("wait error\n");

    printf("pid = %d\n", pid);
}

int main()
{
    pid_t pid;

    if (signal(SIGCLD, sig_cld) == SIG_ERR)
        printf("signal error\n");

    if ((pid = fork()) < 0)
    {
        printf("signal fork\n");
    }
    else if (0 == pid)
    {
        sleep(2);
        _exit(0);
    }

    pause();
    exit(0);
}