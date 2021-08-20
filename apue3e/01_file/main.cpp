/**
 * @author clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "file.h"

#define MAX_LEN 1024

static void test()
{
    int fd = -1;
    int len = -1;
    char buf[] = {"tan hui fang\n"};
    char read_buf[MAX_LEN] = {0};

    std::string name = "test.txt";
    File file(name);

    // 写文件
    len = file.file_write(buf, strlen(buf));
    if (len < 0)
    {
        printf("write fail\n");
        exit(-1);
    }
    printf("write len[%d]:%s\n", len, buf);

    // 移动读写位置
    file.file_lseek(0, SEEK_SET);

    // 读文件
    memset(read_buf, 0, sizeof(read_buf));
    len = file.file_read(read_buf, sizeof(read_buf));
    if (len < 0)
    {
        printf("read fail\n");
        exit(-1);
    }
    printf("read len[%d]:%s\n", len, read_buf);
}

int main()
{
    test();
    return 0;
}


