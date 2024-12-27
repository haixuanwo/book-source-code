/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:21:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 15:12:51
 * @Description: file content
 */

#include <thread>
#include <iostream>
#include <vector>
#include <functional>

// 生成一批线程并等待他们完成
void do_work(unsigned int id)
{
    std::cout << "Thread " << id << " started\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " finished\n";
}

void f()
{
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < 20; ++i)
    {
        threads.emplace_back(do_work, i);
        // threads.push_back(do_work, i);
    }

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main()
{
    f();
}
