/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-26 20:02:11
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-26 20:03:14
 * @Description: file content
 */

#include "03_epoll.h"

int main(int argc, char *argv[])
{
    TcpServer tcpServer(atoi(argv[1]));
    tcpServer.init();
    tcpServer.start();
    
    return 0;
}
