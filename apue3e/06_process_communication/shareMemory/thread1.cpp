/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-08-21 11:07:43
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-21 16:15:22
 * @Description: file content
 */
#include "share_memory.h"

int main()
{
	ShareMemory csm("thp", 4);
#if 1
    csm.test_threads_race(100);
#else
    uint32_t count = 0;
    while (1)
    {
        count++;
        csm.write_data((uint8_t *)&count, sizeof(count));
        printf("T --- count[%u]\n", count);
        sleep(1);
    }
#endif
	return 0;
}
