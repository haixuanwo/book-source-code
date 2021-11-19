/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 14:42:32
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 19:12:42
 * @Description: 消息队列收消息
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
        mq.recv(&msg);
        printf("type[%ld] buf[%s]\n", msg.mtype, msg.buf);
    }
    return 0;
}
