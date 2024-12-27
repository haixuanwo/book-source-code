/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:21:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 15:07:33
 * @Description: file content
 */

#include <thread>
#include <iostream>

// scoped_thread和示例用法,一旦所有权转移到该对象其他线程就不可以动它了，
// 保证退出一个作用域线程完成

class scoped_thread
{
    std::thread t;

public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
        if (!t.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};

void do_something(int& i)
{
    ++i;
    std::cout << "do_something(" << i << ")" << std::endl;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{
    std::cout << "do_something_in_current_thread()" << std::endl;
}

void f()
{
    int some_local_state = 0;

    scoped_thread t(std::thread());
    // scoped_thread t(std::thread(func(some_local_state)));
    do_something_in_current_thread();
}

int main()
{
    f();
    return 0;
}
