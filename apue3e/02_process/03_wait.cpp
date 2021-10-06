/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-6
 */

#include <sys/wait.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

void pr_exit(int status)
{
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, signal = %d\n", WTERMSIG(status));
    else if (WIFSTOPPED(status))
        printf("child stopped, signal = %d\n", WSTOPSIG(status));
}

int main()
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)
	{
	    perror("fork error");
        exit(-1);
    }
	else if (pid == 0)				/* child */
	{
	    exit(7);
    }

	if (wait(&status) != pid)		/* wait for child */
	{
	    perror("wait error");
        exit(-1);
    }
	pr_exit(status);				/* and print its status */

	if ((pid = fork()) < 0)
	{
	    perror("fork error");
        exit(-1);
    }
	else if (pid == 0)				/* child */
		abort();					/* generates [6]SIGABRT */

	if (wait(&status) != pid)		/* wait for child */
	{
	    perror("wait error");
        exit(-1);
    }
	pr_exit(status);				/* and print its status */

	if ((pid = fork()) < 0)
	{
	    perror("fork error");
        exit(-1);
    }
	else if (pid == 0)				/* child */
		status /= 0;				/* divide by 0 generates [8]SIGFPE */

	if (wait(&status) != pid)		/* wait for child */
	{
	    perror("wait error");
        exit(-1);
    }
	pr_exit(status);				/* and print its status */

	exit(0);
}

