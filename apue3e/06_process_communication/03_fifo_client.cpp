/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 11:53:57
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 11:55:07
 * @Description: 有名管道客户端
 */

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO "/tmp/fifo.tmp"

using namespace std;

int main()
{
    int fd;
    char buff[32];

    fd = open(FIFO, O_WRONLY);
    if (fd == -1)
    {
        printf("open error!\n");
        return -1;
    }

    while(1)
    {
        memset(buff, 0, sizeof(buff));
        cout<<"请输入数据："<<endl;
        cin>>buff;
        if (write(fd, buff, strlen(buff)) == -1)
        {
            printf("open error!\n");
            return -1;
        }
    }

    return 0;
}
