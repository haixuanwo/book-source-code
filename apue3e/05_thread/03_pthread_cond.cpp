/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-18 20:14:45
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 20:46:58
 * @Description: 条件变量
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


/**
 * pthread_cond_init        初始化条件变量
 * pthread_cond_wait        等待被唤醒
 * pthread_cond_timedwait   超时则不等待
 * pthread_cond_signal      唤醒指定的等待
 * pthread_cond_broadcast   唤醒所有的等待
 * pthread_cond_destroy     销毁条件变量
 */
class Mutex
{
public:
    Mutex()
    {
        pthread_mutex_init(&mutex, nullptr);
    }

    void lock()
    {
        printf("lock ----\n");
        pthread_mutex_lock(&mutex);
        // pthread_mutex_trylock 加锁失败直接退出
        // pthread_mutex_timedlock 设定时间内还未加锁成功则退出
    }

    void unlock()
    {
        printf("unlock ----\n");
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_t *get_mutex()
    {
        return &mutex;
    }

    ~Mutex()
    {
        pthread_mutex_destroy(&mutex);
    }

private:
    pthread_mutex_t mutex;
};

class Cond
{
public:
    Cond()
    {
        pthread_cond_init(&cond, nullptr);
    }

    void wait(pthread_mutex_t *mutex)
    {
        pthread_cond_wait(&cond, mutex);
    }

    void signal()
    {
        pthread_cond_signal(&cond);
    }

    ~Cond()
    {
        pthread_cond_destroy(&cond);
    }

private:
    pthread_cond_t cond;
};

class Sync
{
public:
    void lock()
    {
        mutex.lock();
    }

    void unlock()
    {
        mutex.unlock();
    }

    void wait()
    {
        cond.wait(mutex.get_mutex());
    }

    void signal()
    {
        cond.signal();
    }
private:
    Mutex mutex;
    Cond  cond;
};

void *print(void *ptr)
{
   Sync *sync = (Sync *)ptr;

    while(1)
    {
        sync->lock();
        printf("hello ----wait\n");
        sync->wait();
        sync->unlock();
        break;
    }

    return nullptr;
}

int main()
{
    pthread_t pth;
    Sync sync;

    int ret = pthread_create(&pth, nullptr, print, (void *)&sync);
    if (ret != 0)
    {
        printf("create fail\n");
        return -1;
    }

    sleep(5);
    sync.signal();

    pause();

    return 0;
}
