/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 16:55:40
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-20 17:49:26
 * @Description: poll
 */

#include "02_poll.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("please input port\n");
        return -1;
    }

    TcpServer tcpServer(atoi(argv[1]));

    if(!tcpServer.init())
    {
        printf("tcp server init fail\n");
        return -1;
    }

    tcpServer.start();

    return 0;
}
