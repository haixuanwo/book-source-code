/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-18 19:56:04
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 20:12:56
 * @Description: 线程同步
 */

/**
 * pthread_mutex_init       初始化互斥变量
 * pthread_mutex_lock       加锁
 * pthread_mutex_trylock    尝试加锁
 * pthread_mutex_unlock     解锁
 * pthread_mutex_destroy    销毁
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

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

    ~Mutex()
    {
        pthread_mutex_destroy(&mutex);
    }

private:
    pthread_mutex_t mutex;
};

class CLock
{
public:
    CLock()
    {
        mutex.lock();
    }

    ~CLock()
    {
        mutex.unlock();
    }
private:
    Mutex mutex;
};

int main()
{
    CLock lock;
    sleep(5);
    return 0;
}
