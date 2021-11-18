/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-10-24 17:04:54
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 18:40:22
 * @Description: file content
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

int File::file_readn(void *buf, size_t count)
{
    size_t  nleft;
    ssize_t nread;
    char *ptr = (char *)buf;

    nleft = count;
    while (nleft > 0)
    {
        nread = read(fd, ptr, nleft);
        if (nread < 0)
        {
            if (nleft == count)
                return -1;
            else
                break;
        }
        else if (0 == nread)
        {
            break;
        }
        nleft -= nread;
        ptr   += nread;
    }

    return (count - nleft);
}

int File::file_writen(void *buf, size_t count)
{
    size_t nleft;
    ssize_t nwritten;
    char *ptr = (char *)buf;

    nleft = count;
    while (nleft > 0)
    {
        nwritten = write(fd, ptr, nleft);
        if (nwritten < 0)
        {
            if (nleft == count) // 一个都没write成功
                return -1;
            else
                break;
        }
        else if (0 == nwritten)
        {
            break;
        }
        nleft -= nwritten;
        ptr   += nwritten;
    }

    return (count - nleft);
}

int File::file_lseek(int offset, int whence)
{
    return lseek(fd, offset, whence);
}

File::~File()
{
    close(fd);
}

