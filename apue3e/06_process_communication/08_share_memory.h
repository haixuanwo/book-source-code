/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 16:50:49
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 17:40:02
 * @Description: 共享内存
 */

#ifndef SHARE_MEMORY_H
#define SHARE_MEMORY_H

extern "C"{
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
}

class SharedMemory
{
public:
    SharedMemory(key_t key, size_t size)
    {
        shmId = -1;
        shm = nullptr;
        this->key = key;
        this->size = size;
    }

    bool init()
    {
        shmId = shmget(key, size, 0666|IPC_CREAT);
        if (shmId < 0)
        {
            printf("shmget fail\n");
            return false;
        }

        //将共享内存连接到当前进程的地址空间
        shm = shmat(shmId, nullptr, 0);
        if(shm == (void*)-1)
        {
            printf("shmat failed\n");
            return false;
        }

        return true;
    }

    bool write_data(char *dataBuf, int dataLen)
    {
        if (nullptr == dataBuf || dataLen <= 0)
        {
            printf("write data buf or data len error\n");
            return false;
        }

        if (dataLen > size)
        {
            printf("the data len[%d] than longer %lu\n", dataLen, size);
            return false;
        }

        memcpy(shm, dataBuf, dataLen);
        return true;
    }

    bool read_data(char *dataBuf, int dataBufSize, int readLen)
    {
        if (nullptr == dataBuf || readLen <= 0)
        {
            printf("read data buf or data len error\n");
            return false;
        }

        if (readLen > size || readLen > dataBufSize)
        {
            printf("the read len[%d] error\n", readLen);
            return false;
        }

        memcpy(dataBuf, shm, readLen);
        return true;
    }

    void destroy()
    {
        //删除共享内存
	    shmctl(shmId, IPC_RMID, 0);
    }

    ~SharedMemory()
    {
        //把共享内存从当前进程中分离
        shmdt(shm);
    }
private:
    int shmId;
    void *shm;      // 共享存储地址

    key_t key;
    size_t size;    // 共享空间大小
};

#endif
