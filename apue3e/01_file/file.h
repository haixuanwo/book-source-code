/**
 * @author clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-20
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
    int file_lseek(int offset, int whence);
    ~File();
private:
    int fd;
};

#endif

