/**
 * @author clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-21
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

void show_info(char *message)
{
    unsigned int times = 0;
    while(1)
    {
        times++;

        if (times > 10)
            break;

        printf("%s:%d\n", message, getpid());
        sleep(1);
    }
}

void pr_exit(int status)
{
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d\n", WTERMSIG(status));
    else if (WIFSTOPPED(status))
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    else
        printf("no ==========\n");
}

int main(int argc, char *argv[])
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
    {
        printf("fork error\n");
        exit(-1);
    }
    else if (0 == pid)
    {
        show_info("I'm child");
        exit(7);
    }
    else
    {
        show_info("I'm parent");
        wait(&status); // 接收到任意进程退出都会返回
        pr_exit(status);
    }

    return 0;
}

