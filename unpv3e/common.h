/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-26
 */

#ifndef COMMON_H
#define COMMON_H

#include <unistd.h>
#include <errno.h>

/**
 * @brief 读n个字节
 * @param fd    文件描述符
 * @param buf   存数据的缓存
 * @param n     读取的字节数
 * @return      -1：失败，大于0：读到的字节数
 */
int readn(int fd, char *buf, int n);

/**
 * @brief 读一行，若读到最大字节数则返回
 * @param fd    文件描述符
 * @param buf   存数据的缓存
 * @param maxLen读取的最大字节数
 * @return int  读到的字节数
 */
int read_line(int fd, char *buf, int maxLen);

/**
 * @brief 写n个字节
 * @param fd    文件描述符
 * @param buf   存数据的缓存
 * @param n     写的字节数
 * @return      写入的字节数
 */
int writen(int fd, char *buf, int n);

#endif

