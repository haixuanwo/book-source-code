/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 17:25:49
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 18:04:46
 * @Description: 信号量
 */

/**
 * system V
 * semget   新建信号量
 * semctl   初始化或删除
 * semop    修改信号量的值
 *
 * POSIX
 * sem_open 新建
 * sem_close 关闭，未删除
 * sem_unlink 删除
 * sem_wait 信号量-1操作
 * sem_trywait 尝试-1
 * sem_post 信号量+1操作
 * sem_getvalue 获取当前信号量值
 *
 * P等待信号量：当信号量sv值为0时，程序等待；当信号量sv值大于0时，信号量减1，程序继续运行。
 * V发送信号量：将信号量sv值加1。
 *
 * 不同的进程，只要使用相同的名字，就是指同一个信号量
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

extern "C"{
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <string.h>
}

#include <string>
#include <iostream>

class Semaphore
{
public:
	Semaphore(std::string &name)
	{
		sem = nullptr;
		this->name = name;
	}

    /**
     * @brief 初始化信号量
     *
     * @param sema_num 信号量初始数量
     * @return true
     * @return false
     */
	bool init(unsigned int sema_num)
	{
		std::cout<<name;
		sem = sem_open(name.c_str(), O_CREAT|O_RDWR, 0666, sema_num);
		if(sem == SEM_FAILED)
		{
			std::cerr << "failed to open mutex sem,error:" << strerror(errno) << std::endl;
			return false;
		}

		return true;
	}

	void wait()
	{
		sem_wait(sem);
	}

	void trywait()
	{
		sem_trywait(sem);
	}

	void waittimeout()
	{
		struct timespec ts;
		ts.tv_sec = 3;
		ts.tv_nsec = 0;
		sem_timedwait(sem, &ts);
	}

	void post()
	{
		sem_post(sem);
	}

	int get_value()
	{
		int value = 0;
		sem_getvalue(sem, &value);
		return value;
	}

	/**
	 * @brief 销毁，影响到其他进程
	 */
	void destroy()
	{
		sem_unlink(name.c_str());
	}

	/**
	 * @brief 关闭后，其他进程还能正常使用
	 */
	~Semaphore()
	{
		sem_close(sem);
	}

private:
	sem_t *sem;
	std::string name;
};

#endif
