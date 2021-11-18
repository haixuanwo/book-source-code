/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-18 19:28:38
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 19:53:19
 * @Description: thread
 */

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void printids(const char* s)
{
    pid_t pid;
    pthread_t tid;

    pid =getpid();
    tid = pthread_self();

    printf("%s pid %lu tid %lu\n", s, (unsigned long)pid, tid);
}

void *thr_fn(void *arg)
{
    printids("new thread: ");

    // pthread_detach(pthread_self()); // 设置为分离状态，退出时直接释放资源不用让pthread_join处理

    pthread_exit((void *)100);
    //return ((void *)0);
}

int main()
{
    int err;
    void *ret;
    pthread_t ntid;

    err = pthread_create(&ntid, nullptr, thr_fn, nullptr);
    if (0 != err)
    {
        printf("create fail\n");
        return -1;
    }

    printids("main thread:");

    // 组赛等待线程结束
    pthread_join(ntid, &ret);

    printf("ret[%ld]\n", (long)ret);

    // pthread_cancel(ntid); // 停止线程


    sleep(1);
    exit(0);
}
