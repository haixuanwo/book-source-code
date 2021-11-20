/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-20 09:49:14
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-20 15:10:15
 * @Description: select
 */

//#include "01_select.h"
#include "01_select_thread.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("please input port\n");
        return -1;
    }

    TcpServer tcpServer(atoi(argv[1]));

    if (!tcpServer.init())
    {
        printf("tcp server init fail\n");
        return -1;
    }

    tcpServer.start();

    return 0;
}
