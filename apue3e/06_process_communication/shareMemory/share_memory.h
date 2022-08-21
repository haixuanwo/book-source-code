/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-08-21 11:06:27
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-21 16:19:55
 * @Description: file content
 */
#ifndef SHARE_MEMORY_H
#define SHARE_MEMORY_H

extern "C"
{
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
}
#include <iostream>

class ShareMemory
{
public:
	ShareMemory(const char *name, uint32_t size);
	~ShareMemory();

    int write_data(uint8_t *buf, uint32_t len);
	int read_data(uint8_t *buf, uint32_t len);

    void test_threads_race(uint32_t sleepsToWrite);    // 测试多线程竞争

private:
	void *create_share_memory(const char *name, uint32_t size);
	void lock(void);
	void unlock(void);

    const char *name;
	sem_t *m_sem;
	uint32_t m_memSize;
    uint8_t *m_shareMemory;
};

#endif
