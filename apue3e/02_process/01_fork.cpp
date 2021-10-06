#include <stdio.h>
#include <error.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/stat.h>
//#include <fcntl.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char * argv [ ])
{
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != (sizeof(buf)-1))
    {
        perror("write error\n");
        return -1;
    }
    printf("before fork\n");

    pid = fork();
    if (pid < 0)
    {
        perror("fork error\n");
        return -1;
    }
    else if (0 == pid)
    {
        globvar++;
        var++;
    }
    else
    {
        sleep(2);
    }

    printf("parent:pid[%ld], ppid[%ld], glob = %d, var = %d\n",
        (long)getpid(), (long)getppid(), globvar, var);
    exit(0);
}

