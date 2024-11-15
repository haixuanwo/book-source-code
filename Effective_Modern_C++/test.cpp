
#include <iostream>
#include <memory>

decltype(auto) f1()
{
    static int x = 0 ;
    return x;     // 返回的是int;
}

decltype(auto) f2()
{
    static int x = 0;
    return (x);   //返回的是int&
}

void test()
{
    decltype(auto) x1 = f1();
    x1++;
    std::cout << x1 << std::endl;

    decltype(auto) x2 = f2();
    x2++;
    std::cout << x2 << std::endl;
}

// --------------------------------------------------------

class MyClassImpl {
public:
    void doSomething() {
        std::cout << "Doing something!" << std::endl;
    }
};

class MyClass {
public:
    MyClass() {
        pImpl = std::make_unique<MyClassImpl>();
    }

    ~MyClass() { }

    void doSomething()
    {
        pImpl->doSomething();
    }

private:
    std::unique_ptr<MyClassImpl> pImpl;
};



void test_MyClassImpl() {
    MyClass myClass;
    myClass.doSomething();
}

// -----------------------------------------------
#include <utility> // For std::forward

// 假设some_other_function已经定义好了
void some_other_function(int& x) {
    std::cout << "Forwarded as lvalue reference: " << x << std::endl;
}

void some_other_function(int&& x) {
    std::cout << "Forwarded as rvalue reference: " << x << std::endl;
}

template<typename T>
void forward_example(T&& param) {
    // 使用std::forward来保留参数的引用特性
    some_other_function(std::forward<T>(param));
    // some_other_function(param);
}

int test_forward()
{
    int x = 5;
    forward_example(x);       // 应该被转发为lvalue
    forward_example(10);      // 应该被转发为rvalue

    return 0;
}

// ------------------------------
#include <iostream>
#include <future>
#include <thread>

int heavy_computation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
    return x * x;
}

int test_future_async()
{
    // 使用 std::launch::async 启动异步任务
    std::future<int> result = std::async(std::launch::async, heavy_computation, 10);

    // 在此期间，主线程可以继续做其他事情
    std::cout << "主线程继续执行其他任务..." << std::endl;

    // 获取异步任务的结果
    int value = result.get();
    std::cout << "异步计算的结果是: " << value << std::endl;

    return 0;
}


void delayed_print(const std::string& message) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
    std::cout << message << std::endl;
}

int test_future_deferred()
{
    // 使用 std::launch::deferred 启动延迟执行的任务
    std::future<void> deferred_result = std::async(std::launch::deferred, delayed_print, "这是延迟执行的任务");

    // 在此期间，主线程可以继续做其他事情
    std::cout << "主线程继续执行其他任务..." << std::endl;

    // 手动触发任务执行
    deferred_result.get();

    return 0;
}

// ---------------------------------
#include <future>
#include <thread>

void set_promise_value(std::promise<int>&& prms) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
    prms.set_value(42); // 设置值
}

int test_promise_future()
{
    std::promise<int> prms; // 创建 promise 对象
    std::future<int> fut = prms.get_future(); // 获取 future 对象

    // 创建一个线程来设置 promise 的值
    std::thread t(set_promise_value, std::move(prms));

    // 主线程等待获取值
    std::cout << "主线程等待获取值..." << std::endl;
    int value = fut.get(); // 获取值

    std::cout << "获取到的值是: " << value << std::endl;

    t.join(); // 等待线程结束

    return 0;
}


int main(int argc, char* argv[])
{
    // test();
    // test();

    // test_MyClassImpl();

    // test_forward();

    // test_future_async();

    // test_future_deferred();

    test_promise_future();

    return 0;
}
