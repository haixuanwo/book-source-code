/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 19:20:08
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 19:43:23
 * @Description: 使用信号量来实现互斥访问共享内存
 */

#ifndef SEMAPHORE_SHARE_MEMORY_H
#define SEMAPHORE_SHARE_MEMORY_H

#include "06_semaphore.h"
#include "08_share_memory.h"

class SemaShareMemory
{
public:
    SemaShareMemory(key_t key, size_t size, std::string semaName)
    {
        sharedMemory = new SharedMemory(key, size);
        semaphore = new Semaphore(semaName);
    }

    bool init()
    {
        if (!sharedMemory->init())
        {
            return false;
        }

        if (!semaphore->init(1))
        {
            return false;
        }

        return true;
    }

    bool read_data(char *dataBuf, int dataBufSize, int readLen)
    {
        semaphore->wait();   // 消耗一个信号量

        if(!sharedMemory->read_data(dataBuf, dataBufSize, readLen))
        {
            printf("read fail\n");
            semaphore->post();
            return false;
        }

        semaphore->post();   // 产生一个信号量

        return true;
    }

    bool write_data(char *dataBuf, int writeLen)
    {
        semaphore->wait();   // 消耗一个信号量

        if(!sharedMemory->write_data(dataBuf, writeLen))
        {
            printf("write fail\n");
            semaphore->post();
            return false;
        }

        sleep(5);

        semaphore->post();   // 产生一个信号量

        return true;
    }

    ~SemaShareMemory()
    {
        delete sharedMemory;
        delete semaphore;
    }

private:
    SharedMemory *sharedMemory;
    Semaphore *semaphore;
};

#endif
