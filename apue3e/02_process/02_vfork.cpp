#include <stdio.h>
#include <error.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int globvar = 6;

int main(int argc, char * argv [ ])
{
    int var;
    pid_t pid;

    var = 88;
    printf("before fork\n");

    // vfork保证子进程调用exec或exit之前，使父进程处于休眠状态
    pid = vfork();
    if (pid < 0)
    {
        perror("fork error\n");
        return -1;
    }
    else if (0 == pid)
    {
        globvar++;
        var++;
        printf("child:pid[%ld], ppid[%ld], glob = %d, var = %d\n",
            (long)getpid(), (long)getppid(), globvar, var);

        _exit(0);
    }

    // 子父进程变量共享
    printf("parent:pid[%ld], ppid[%ld], glob = %d, var = %d\n",
        (long)getpid(), (long)getppid(), globvar, var);
    exit(0);
}


