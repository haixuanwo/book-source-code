/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 17:17:13
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-21 11:34:15
 * @Description: file content
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

    while (1)
    {
        sleep(1);
        if(false == sharedMemory.read_data((char *)&data, sizeof(data), sizeof(data)))
        {
            printf("read fail\n");
            continue;
        }

        printf("writen[%u] data[%u]\n", data.written, data.data);
    }

    pause();

    return 0;
}
