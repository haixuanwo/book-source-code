/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-27
 */

#ifndef MULTI_PROCESS_SERVER
#define MULTI_PROCESS_SERVER

#include <string>
#include <arpa/inet.h>

/**
 * @brief tcp服务器
 */
class Server
{
public:
    Server();

    /**
     * @brief 绑定、监听
     * @param port 供客户端连接的端口
     * @param IP 供客户端连接的IP
     * @return true：成功，false：失败
     */
    bool init(unsigned int port, std::string *IP);

    /**
     * @brief 接收客户端连接请求
     */
    void start();

    /**
     * @brief 给客户端发送当前时间数据
     * @param clientFd 客户端文件描述符
     * @return true：成功，false：失败
     */
    bool send_time(int clientFd);

    ~Server();
private:
    int listenfd;
    struct sockaddr_in servaddr;
};

#endif

