/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 17:38:03
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 19:49:35
 * @Description: 用信号量来实现互斥访问共享内存
 */

#include "10_semaphore_share_memory.h"

#define SHARED_MEMORY_SIZE 1024
#define KEY 6666

typedef struct {
	uint32_t written;
	uint32_t data;
}Data_t;

int main()
{
    Data_t data;
    std::string name = "FFF";
	SemaShareMemory semaShareMemory(KEY, SHARED_MEMORY_SIZE, name);

    if (!semaShareMemory.init())
    {
        printf("semaShareMemory init fail\n");
        return false;
    }

    while (1)
    {
        semaShareMemory.read_data((char *)&data, sizeof(data), sizeof(data));
        printf("writen[%u] data[%u]\n", data.written, data.data);
    }

    return 0;
}
