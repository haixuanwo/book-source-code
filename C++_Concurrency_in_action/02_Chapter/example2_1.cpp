/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:18:42
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 14:46:45
 * @Description: file content
 */
#include <iostream>
#include <thread>

extern "C"
{
#include <unistd.h>
}

void do_something(int& i)
{
    ++i;
    std::cout << "i = " << i << std::endl;
}

struct func
{
    int  &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (int j = 0; j < 1000000; ++j)
        {
            do_something(i);
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach(); // 不等待线程完成
}   // 新的线程可能仍在运行

int main()
{
    oops();
    pause();
    return 0;
}
