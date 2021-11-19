/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 15:12:00
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 17:59:47
 * @Description: 信号量
 */

#include "06_semaphore.h"

#include <iostream>
#include <string>

using namespace std;

void *get_data(void *ptr)
{
	Semaphore *sp = (Semaphore *)ptr;

	while (1)
	{
		sp->wait();
		printf("pthreadID[%lu] I get data so happy\n", pthread_self());
	}
}

void *set_data(void *ptr)
{
	Semaphore *sp = (Semaphore *)ptr;

	while (1)
	{
		printf("Give you a data\n");
		sp->post();
		sleep(3);
	}
}

int main()
{
	int ret = -1;
	pthread_t pth;

	string name = "Linus";

	Semaphore semaphore(name);
	if (!semaphore.init(0))
	{
		printf("semaphore fail\n");
		return -1;
	}

	ret = pthread_create(&pth, nullptr, get_data, (void *)&semaphore);
	if (ret < 0)
	{
		printf("pthread_creat fail\n");
		return -1;
	}

	ret = pthread_create(&pth, nullptr, get_data, (void *)&semaphore);
	if (ret < 0)
	{
		printf("pthread_creat fail\n");
		return -1;
	}

	ret = pthread_create(&pth, nullptr, set_data, (void *)&semaphore);
	if (ret < 0)
	{
		printf("pthread_creat fail\n");
		return -1;
	}

	pause();
	return 0;
}
