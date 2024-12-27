
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <list>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int value)
{
    std::lock_guard<std::mutex> lock(some_mutex);
    some_list.push_back(value);
}

bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> lock(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

int main()
{
    add_to_list(1);
    add_to_list(2);
    add_to_list(3);
    std::cout << "List contains 2: " << list_contains(2) << std::endl;
    std::cout << "List contains 2: " << list_contains(4) << std::endl;

    return 0;
}
