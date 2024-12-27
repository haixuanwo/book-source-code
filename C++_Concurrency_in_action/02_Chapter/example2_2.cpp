/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:21:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-18 17:24:53
 * @Description: file content
 */
#include <iostream>
#include <thread>

void do_something(int& i)
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

void do_something_in_current_thread()
{

}

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);

    try
    {
        do_something_in_current_thread();
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
    return 0;
}
