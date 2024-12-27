/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 17:03:30
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 17:06:15
 * @Description: file content
 */
#include <mutex>
#include <chrono>
#include <iostream>
#include <thread>
#include <condition_variable>

std::condition_variable cv;
bool done;
std::mutex m;

bool wait_loop()
{
    auto const timeout= std::chrono::steady_clock::now() +
        std::chrono::milliseconds(500);

    std::unique_lock<std::mutex> lk(m);

    while(!done)
    {
        if(cv.wait_until(lk,timeout)==std::cv_status::timeout)
            break;

        std::cout << "wait_loop() woke up\n";
    }

    std::cout << "wait_loop() done\n";
    return done;
}

int main(int argc, char* argv[])
{
    std::thread t([&]{
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::lock_guard<std::mutex> lk(m);
            done=true;
        }
        cv.notify_one();
    });

    wait_loop();
    t.join();

    return 0;
}
