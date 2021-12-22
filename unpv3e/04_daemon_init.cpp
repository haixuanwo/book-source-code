/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-12-22 10:25:36
 * @LastEditors: Clark
 * @LastEditTime: 2021-12-22 10:47:46
 * @Description: file content
 */

#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 *
 * ident : 日志消息前的字符串
 * option: LOG_CONS LOG_NDELAY LOG_PERROR LOG_PID
 * faCILITY:为syslog指定默认值
 * void openlog(const char *ident, int option, int facility);
 *
 * priority : LOG_EMERG LOG_ALERT LOG_CRIT LOG_ERR LOG_WARNING LOG_NOTICE LOG_INFO LOG_DEBUG
 * void syslog(int priority, const char *format, ...);
 *
 * void closelog(void);
 *
 */
#define MAXFD 64
// extern int daemon_proc;// defined in error.c

int daemon_init(const char* pname, int facility)
{
    int i;
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        return -1;
    }
    else if (pid)
        _exit(0); // parent terminates

    // child 1 continues ...
    if (setsid() < 0)
        return -1;

    signal(SIGHUP, SIG_IGN);
    if ((pid = fork()) < 0)
    {
        return -1;
    }
    else if (pid)
        _exit(0);

    // child 2 continues ...
    // daemon_proc = 1;

    chdir("/");

    // close off file descriptors
    for (int i = 0; i < MAXFD; i++)
        close(i);

    // redirect stdin, stdout, stderr to /dev/null
    open("/dev/null", O_RDONLY);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_RDWR);

    openlog(pname, LOG_PID, facility);

    return 0;
}

int main(int argc, char *argv[])
{
    daemon_init("txh", LOG_USER);

    while (1)
    {
        syslog(LOG_INFO, "hello:%s", "fuck");
        sleep(1);
    }

    return 0;
}
