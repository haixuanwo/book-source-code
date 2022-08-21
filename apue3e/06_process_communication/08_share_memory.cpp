/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 16:30:27
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-21 11:32:03
 * @Description: 共享内存
 */

/**
 * 同步访问方式：信号量、记录锁、互斥量
 *
 * shmget 获取共享存储标识符
 * shmctl 操作共享存储段
 * shmat  连接共享存储段地址空间
 * shmdt  删除存储标识符
 */

#include <unistd.h>
#include <stdlib.h>
#include <string>

#include "08_share_memory.h"

#define SHARED_MEMORY_SIZE 1024
#define KEY 6666

typedef struct {
	uint32_t written;//作为一个标志，非0：表示可读，0表示可写
	uint32_t data;
}Data_t;

int main()
{
    Data_t data;
	SharedMemory sharedMemory(KEY, SHARED_MEMORY_SIZE);

    if (!sharedMemory.init())
    {
        printf("shared memory init fail\n");
        return -1;
    }

    data.written = 120;
    data.data = 119;

    while (1)
    {
        if(false == sharedMemory.write_data((char *)&data, sizeof(data)))
        {
            msleep(100);
            printf("write fail\n");
        }
    }



    pause();
}
