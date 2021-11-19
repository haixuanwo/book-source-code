/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-19 18:48:55
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-19 19:14:22
 * @Description: message queue
 */

/**
 * IPC结构：消息队列、信号量、共享存储段
 * 标识符
 * 键：关联IPC对象
 *
 * ftok 将路径名和项目ID转换成键
 *  msgget
 *  msgctl
 *  msgsnd
 *  msgrcv
 */

#ifndef MSG_QUEUE
#define MSG_QUEUE

extern "C" {
#include <sys/ipc.h>
#include <sys/msg.h>
}

#include <string>

typedef struct _msg
{
    long mtype;
    char buf[256];
}Msg_t;

class MsgQueue
{
public:
    MsgQueue(std::string &path, int projectId)
    {
        this->path = path;
        this->projectId = projectId;
    }

    bool init()
    {
        // generate key
        key_t key = ftok(path.c_str(), projectId);
        if(key == -1)
        {
            perror("ftoke failed");
            return false;
        }
        printf("key = %#x\n", key);

        // create message queue
        msgId = msgget(key, 0666 | IPC_CREAT);
        if (-1 == msgId)
        {
            perror("msgget failed");
            return false;
        }

        return true;
    }

    int send(Msg_t *send_msg)
    {
        return msgsnd(msgId, send_msg, sizeof(send_msg->buf), 0);
    }

    ssize_t recv(Msg_t *recv_msg)
    {
        return msgrcv(msgId, recv_msg, sizeof(*recv_msg)-sizeof(recv_msg->mtype), 0, 0);
    }

    void destroy()
    {
        // destroy the messsage queue
        msgctl(msgId, IPC_RMID, nullptr);
    }

    ~MsgQueue()
    {

    }

private:
    int msgId;
    std::string path;
    int projectId;
};

#endif
