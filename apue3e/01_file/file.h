/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-10-24 17:04:54
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-18 18:22:20
 * @Description: file content
 */

#ifndef FILE_H
#define FILE_H

#include <string>

class File
{
public:
    File(std::string &name);
    int file_read(void *buf, size_t count);
    int file_write(void *buf, size_t count);
    int file_readn(void *buf, size_t count);
    int file_writen(void *buf, size_t count);
    int file_lseek(int offset, int whence);
    ~File();
private:
    int fd;
};

#endif

