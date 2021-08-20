/**
 * @author clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-20
 */
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/types.h>
#include <string.h>

#define MAX_LEN 1024

static void test()
{
    int fd = -1;
    int len = -1;
    char buf[] = {"tan heng\n"};
    char read_buf[MAX_LEN] = {0};

    // 打开文件
    fd = open("test.txt", O_CREAT| O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    if (fd < 0)
    {
        printf("open fail\n");
        exit(-1);
    }

    // 写文件
    len = write(fd, buf, strlen(buf));
    if (len < 0)
    {
        printf("open fail\n");
        exit(-1);
    }
    printf("write len[%d]:%s\n", len, buf);

    // 移动读写位置
    lseek(fd, 0, SEEK_SET);

    // 读文件
    memset(read_buf, 0, sizeof(read_buf));
    len = read(fd, read_buf, sizeof(read_buf));
    if (len < 0)
    {
        printf("open fail\n");
        exit(-1);
    }
    printf("read len[%d]:%s\n", len, read_buf);

    // 关闭文件
    close(fd);
}

int main()
{
    test();
    return 0;
}

