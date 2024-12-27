/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:21:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 14:56:36
 * @Description: file content
 */

#include <thread>
#include <iostream>

extern "C"
{
#include <unistd.h>
}

class thread_guard
{
    std::thread &t;
public:
    explicit thread_guard(std::thread &t_):t(t_)
    {

    }

    ~thread_guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

void do_something(int &i)
{
    ++i;
    std::cout << "i = " << i << std::endl;
}

struct func
{
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (int j = 0; j < 1000000; ++j)
        {
            do_something(i);
        }
    }
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);

    thread_guard g(my_thread);

    try
    {
        // todo
    }
    catch(...)
    {
        my_thread.join();   // 异常中断
        throw;
    }

    my_thread.join();       // 正常结束
}

int main()
{
    f();
    pause();
    return 0;
}
