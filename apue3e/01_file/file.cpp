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
#include <string.h>

#include "file.h"

File::File(std::string &name)
{
    // 打开文件
    fd = open(name.c_str(), O_CREAT| O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    if (fd < 0)
    {
        printf("open fail\n");
        exit(-1);
    }
}

int File::file_read(void *buf, size_t count)
{
    return read(fd, buf, count);
}

int File::file_write(void *buf, size_t count)
{
    return write(fd, buf, count);
}

int File::file_lseek(int offset, int whence)
{
    return lseek(fd, offset, whence);
}

File::~File()
{
    close(fd);
}

