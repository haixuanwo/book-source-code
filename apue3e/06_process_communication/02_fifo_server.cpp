/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 11:37:49
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 11:55:00
 * @Description: fifo 有名管道
 */

/**
 * 与无名管道区别：不相关进程间也可通信
 * mkfifo
 * mkfifoat
 * 两种用途：（1）shell命令之间传输数据无需创建中间临时文件
 *         （2）FIFO汇聚客户进程和服务进程二者传递数据
 *
 * ftok 路径名和项目ID产生一个键
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
    char buff[48];
    unlink(FIFO);

    if (mkfifo(FIFO, 0666) < 0)/*新创建的FIFO模式*/
    {
        printf("create error!\n");
        return -1;
    }

    fd = open(FIFO, O_RDONLY); //设为阻塞模式
    if (fd == -1)
    {
        printf("open error!\n");
        return -1;
    }

    while(1)
    {
        memset(buff, 0, sizeof(buff));
        if(read(fd, buff, sizeof(buff))>0)
        {
            printf("read data is %s\n", buff);
        }
    }

    return 0;
}
