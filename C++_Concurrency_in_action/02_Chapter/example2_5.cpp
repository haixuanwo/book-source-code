/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:21:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 15:02:20
 * @Description: file content
 */

#include <thread>
#include <iostream>

void some_function()
{
    std::cout << "Hello from some_function" << std::endl;
}

void some_other_function(int)
{
    std::cout << "Hello from some_other_function" << std::endl;
}

std::thread f()
{
    void some_function();
    return std::thread(some_function);
}

std::thread g()
{
    void some_other_function(int);
    std::thread t(some_other_function, 42);
    return t;
}

#if 0
// 控制权从函数中转移
void f(std::thread t)
void g()
{
    void some_other_function();
    f(std::thread(some_function));

    std::thread t(some_function);
    f(std::move(t)); // 转移控制权
}
#endif

int main()
{
    std::thread t1 = f();
    t1.join();

    std::thread t2 = g();
    t2.join();

    return 0;
}
