/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 15:30:36
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 15:41:16
 * @Description: file content
 */
#include <mutex>
#include <stack>
#include <memory>
#include <exception>
#include <iostream>

struct empty_stack: std::exception
{
    const char* what() const throw()
    {
        return "empty stack";
    }
};

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack(){ }

    threadsafe_stack(const threadsafe_stack &other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }


    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty())
        {
            throw empty_stack();
        }

        std::shared_ptr<T> res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty())
        {
            throw empty_stack();
        }

        value = data.top();
        data.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    threadsafe_stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::shared_ptr<int> p = s.pop();
    std::cout << *p << std::endl;

    int value;
    s.pop(value);
    std::cout << value << std::endl;

    std::cout << s.empty() << std::endl;

    return 0;
}
