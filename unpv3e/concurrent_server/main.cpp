/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-27
 */

#include <stdio.h>
#include <stdlib.h>

#include "multi_process_server.h"

int main(int argc, char * argv [ ])
{
    bool ret = false;
    Server server;

    if (argc < 2)
    {
        printf("please input port\n");
        return -1;
    }

    ret = server.init(atoi(argv[1]), nullptr);
    if(false == ret)
    {
        printf("server init error\n");
        return -1;
    }

    server.start();

    return 0;
}

