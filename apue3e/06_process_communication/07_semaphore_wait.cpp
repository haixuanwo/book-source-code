/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 16:16:55
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 17:59:22
 * @Description: 信号量wait
 */

#include <iostream>
#include <string>
#include "06_semaphore.h"

using namespace std;

int main()
{
    string name = "Linus";
	Semaphore semaphore(name);

	if (!semaphore.init(0))
	{
		printf("semaphore fail\n");
		return -1;
	}

    while (1)
    {
        semaphore.wait();
        printf("I get sema\n");
    }

    return 0;
}
