/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 12:01:33
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 19:10:59
 * @Description: 消息队列
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#include "04_msg_queue.h"

int main()
{
    std::string path = "/tmp";
    int projectId = 1000;

    MsgQueue mq(path, projectId);
    if (!mq.init())
    {
        printf("msg queue init fail\n");
        return false;
    }

    Msg_t msg;
    while(1)
    {
        scanf("%ld %s", &msg.mtype, msg.buf);
        mq.send(&msg);
    }
    return 0;
}
