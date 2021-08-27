
#ifndef FOPEN_H
#define FOPEN_H

#include <stdio.h>
#include <string>

class File
{
public:
    File(std::string &name);
    int file_read(char *buf, int len);
    int file_write(char *buf, int len);
    int file_seek(int offset, int whence);
    ~File();
private:
    FILE *fp;
};

#endif

