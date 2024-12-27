
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <list>
#include <algorithm>

extern "C"
{
#include <unistd.h>
}

class some_data
{
    int a;
    std::string b;

public:
    void do_something()
    {
        std::cout << "Doing something " << std::endl;
    }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex mtx;

public:
    template<typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> lock(mtx);
        func(data);
    }
};

some_data *unprotected;

void malicious_function(some_data &data)
{
    unprotected = &data;
}

data_wrapper data_wrapper_obj;

void foo()
{
    data_wrapper_obj.process_data(malicious_function);
    unprotected->do_something();
}

int main()
{
    foo();
    pause();
    return 0;
}
