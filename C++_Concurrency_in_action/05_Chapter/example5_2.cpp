/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 18:47:25
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 18:47:40
 * @Description: file content
 */
#include <vector>
#include <atomic>
#include <iostream>
#include <chrono>
#include <thread>

std::vector<int> data;
std::atomic_bool data_ready(false);

void reader_thread()
{
    while(!data_ready.load())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::cout<<"The answer="<<data[0]<<"\n";
}

void writer_thread()
{
    data.push_back(42);
    data_ready=true;
}
