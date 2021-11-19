/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 10:48:13
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 11:29:45
 * @Description: 无名管道
 */

/**
 * 1、只能在具有公共祖先进程间使用
 * 2、假定为半双工
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINE 1024

int main()
{
    int n;
    int parent_to_child[2];
    int child_to_parent[2];
    pid_t pid;
    char parent_buf[MAX_LINE];
    char child_buf[MAX_LINE];

    char parent_str[] = {"xxxxxxxxxxxxxxxxxxxxx"};
    char child_str[]  = {"ooooooooooooooooooooo"};

    // 父进程读，子进程写
    if (pipe(child_to_parent) < 0)
    {
        printf("pipe fail\n");
        return -1;
    }

    // 父进程写，子进程读
    if (pipe(parent_to_child) < 0)
    {
        printf("pipe fail\n");
        return -1;
    }

    if ((pid = fork()) < 0)
    {
        printf("fork fail\n");
        return -1;
    }
    else if (pid > 0)
    {
        close(parent_to_child[0]);
        close(child_to_parent[1]);
        while (1)
        {
            sleep(3);
            write(parent_to_child[1], parent_str, sizeof(parent_str));

            read(child_to_parent[0], parent_buf, sizeof(parent_buf));
            printf("parent_pid[%d] get: %s\n", getpid(), parent_buf);
        }
    }
    else
    {
        close(parent_to_child[1]);
        close(child_to_parent[0]);
        while (1)
        {
            read(parent_to_child[0], child_buf, sizeof(child_buf));
            printf("child_pid[%d] get: %s\n", getpid(), child_buf);

            write(child_to_parent[1], child_str, sizeof(child_str));
        }
    }

    exit(0);
}
