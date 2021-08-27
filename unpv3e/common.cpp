
#include "common.h"

/**
 * @brief 读n个字节
 * @param fd    文件描述符
 * @param buf   存数据的缓存
 * @param n     读取的字节数
 * @return      -1：失败，大于0：读到的字节数
 */
int readn(int fd, char *buf, int n)
{
    int nleft = 0;
    int nread = 0;
    char *ptr = nullptr;

    if (fd < 0 || nullptr == buf || n < 0)
    {
        return -1;
    }

    ptr = buf;
    nleft = n;

    while (nleft > 0)
    {
        nread = read(fd, ptr, nleft);
        if (nread < 0)
        {
            if (errno == EINTR)
                nread = 0;
            else
                return -1;
        }
        else if (0 == nread)
        {
            break;
        }

        nleft -= nread;
        ptr   += nread;
    }

    return (n - nleft);
}

/**
 * @brief 读一行，若读到最大字节数则返回
 * @param fd    文件描述符
 * @param buf   存数据的缓存
 * @param maxLen读取的最大字节数
 * @return int  读到的字节数
 */
int read_line(int fd, char *buf, int maxLen)
{
    int n = 0;
    int rc = 0;
    char c = '0';
    char *ptr = NULL;

    if (fd < 0 || nullptr == buf || maxLen < 0)
    {
        return -1;
    }

    ptr = buf;

    for (n = 1; n < maxLen; n++)
    {
    again:
        if ((rc = read(fd, &c, 1)) == 1)
        {
            *ptr++ = c;
            if ('\n' == c)
            {
                break;
            }
            else if (0 == rc)
            {
                *ptr = 0;
                return (n - 1);
            }
            else
            {
                if (errno == EINTR)
                    goto again;
                return -1;
            }
        }
    }

    *ptr = 0;
    return n;
}

/**
 * @brief 写n个字节
 * @param fd    文件描述符
 * @param buf   存数据的缓存
 * @param n     写的字节数
 * @return      写入的字节数
 */
int writen(int fd, char *buf, int n)
{
    int nleft = 0;
    int nwritten = 0;
    const char *ptr = nullptr;

    if (fd < 0 || nullptr == buf || n < 0)
    {
        return -1;
    }

    ptr = buf;
    nleft = n;

    while (nleft > 0)
    {
        nwritten = write(fd, ptr, nleft);
        if (nwritten <= 0 && errno == EINTR)
        {
            nwritten = 0;
        }
        else
        {
            return -1;
        }

        nleft -= nwritten;
        ptr += nwritten;
    }

    return n;
}

int main(int argc, char *argv[])
{
    return 0;
}

