#include "share_memory.h"

ShareMemory::ShareMemory(const char *name, uint32_t size):m_memSize(size)
{
    this->name = name;
	m_sem = sem_open(name, O_CREAT, 0X666, 1);
	if(SEM_FAILED == m_sem)
	{
		printf("sem_open error");
	}

	lock();
	m_shareMemory = (uint8_t *)create_share_memory(name, m_memSize);
	unlock();
}

/*
 * brief:  写入数据到共享内存
 * param1: buffer 写入数据buf
 * param2: length 写入数据长度
 * return: 返回写入数据的长度
**/
int ShareMemory::write_data(uint8_t *buf, uint32_t len)
{
	if(m_memSize < len)
	{
		printf("Input length[%u] exceeds memory length[%u] error", len, m_memSize);
		return -1;
	}

	lock();
	memcpy(m_shareMemory, buf, len);
	unlock();
	return len;
}

/*
 * brief:  从共享内存读取数据
 * param1: buffer 读取数据buf
 * param2: length 读取数据长度
 * return: 返回读取数据的长度
**/
int ShareMemory::read_data(uint8_t *buf, uint32_t len)
{
	if(m_memSize < len) // 获取数据越界
	{
		len = m_memSize;
	}

	lock();
	memcpy(buf, m_shareMemory, len);
	unlock();
	return len;
}

/**
 * @brief 测试多线程访问
 */
void ShareMemory::test_threads_race(uint32_t sleepsToWrite)
{
    // #define TEST_THREAD_RACE    // 打开宏则产生多线程竞争问题
    uint32_t count = 0;
    uint32_t lastCount = 0;

    while (1)
    {
        #ifndef TEST_THREAD_RACE
        lock();
        #endif

        count = *((uint32_t *)m_shareMemory);
        printf("before count[%u]\n", count);

        if (lastCount > count)
        {
            printf("the other thread error change lastCount[%u] count[%u]\n", lastCount, count);
            break;
        }

        usleep(1000*sleepsToWrite);

        count++;
        *((uint32_t *)m_shareMemory) = count;
        printf("after count[%u]\n", count);
        lastCount = count;

        #ifndef TEST_THREAD_RACE
        unlock();
        #endif

        usleep(1000*100);
    }
}

void ShareMemory::lock(void)
{
    sem_wait(m_sem);
}

void ShareMemory::unlock(void)
{
    sem_post(m_sem);
}

/*
 * brief:  创建共享内存
 * param1: name
 * size:   创建内存大小
**/
void * ShareMemory::create_share_memory(const char *name, uint32_t size)
{
	int fd, shmid;
	void *memory;
	struct shmid_ds buf;
	char filename[32];

	snprintf(filename, 32, "/tmp/.%s", name);
	if((fd = open(filename, O_RDWR|O_CREAT|O_EXCL)) > 0)
	{
		close(fd);
	}

	shmid = shmget(ftok(filename, 'g'), size, IPC_CREAT);
	if (-1 == shmid)
    {
        perror("shmget err");
        return NULL;
    }
    //printf("shmid:%d \n", shmid);

	memory = shmat(shmid, NULL, 0);
	if ((void *)-1 == memory)
    {
        perror("shmget err");
        return NULL;
    }

	shmctl(shmid, IPC_STAT, &buf);
	if (buf.shm_nattch == 1)
	{
		memset(memory, 0, size);
	}

	return memory;
}

ShareMemory::~ShareMemory()
{
	shmdt(m_shareMemory);
	sem_close(m_sem);
    sem_unlink(name);
}
