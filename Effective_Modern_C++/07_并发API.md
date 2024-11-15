<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-15 11:19:40
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-15 13:45:41
 * @Description: file content
-->

# 35. 优先考虑基于任务的编程而非基于线程的编程

std::future<R> async(std::launch policy, Fn&& fn, Args&&... args);


基于线程的代码：

    int doAsyncWork();
    std::thread t(doAsyncWork);

基于任务的代码：

    auto fut = std::async(doAsyncWork);

我们应该优先考虑基于任务的方法（后面这个），首先async是能够获得doAsyncWork的返回值的，并且如果里面有异常的话，也可以捕捉得到。而且更重要的是，使用后面这种方法可以将线程管理的责任交给std标准库来，不需要自己解决死锁，负载均衡，新平台适配等问题

另外，软件线程（操作系统线程或者系统线程）是操作系统的跨进程管理线程，能够创建的数量比硬件线程要多，但是是一种有限资源，当软件线程没有可用的时候，就会直接抛出异常，即使被调用函数式noexcept的。

下面是几种直接使用线程的情况（当然这些情况并不常见）：
+ 需要访问底层线程实现的API（pthread或者Windows线程库）
+ 需要并且开发者有能力进行线程优化
+ 需要实现C++并发API中没有的技术


# 36. 如果有异步的必要请指定std::launch::threads

+ std::launch::async：指定的时候意味着函数f必须以异步方式进行，即在另一个线程上执行
+ std::launch::deferred 则指f只有在get或者wait函数调用的时候同步执行，如果get或者wait没有调用，则f不执行
+ 如果不指定策略的话（默认方法），则系统会按照自己的估计来推测需要进行什么样的策略（会带来不确定性），感觉还是很危险的！！！所以尽量在使用的时候指定是否是异步或者是同步

```
    auto fut = std::async(f);
    if(fut.wait_for(0s) == std::future_statuc::deferred){....}    //判断是否是同步（是否推迟了）
    else{
        while{fut.wait_for(100ms) != std::future_status::ready}{}//不可能死循环，因为之前有过判断是否是同步
    }
```

# 37. 从各个方面使得std::threads unjoinable

每一个std::thread类型的对象都处于两种状态：joinable和unjoinable

+ joinable：对应底层已运行、可运行或者运行结束的出于阻塞或者等待调度的线程
+ unjoinable： 默认构造的std::thread, 已move的std::thread, 已join的std::thread, 已经分离的std::thread
+ 如果某一个std::thread是joinable的，然后他被销毁了，会造成很严重的后果，（比如会造成隐式join（会造成难以调试的性能异常）和隐式detach（会造成难以调试的未定义行为）），所以我们要保证thread在所有路径上都是unjoinable的：

    class ThreadRAII{
    public:
        enum class DtorAction{join, detach};
        ThreadRAII(std::thread&& t, DtorAction a):action(a), t(std::move(t)){} //把线程交给ThreadRAII处理
        ~THreadRAII(){
            if(t.joinable()){
                if(action == DtorAction::join){
                    t.join();
                }
                else{
                    t.detach();                  //保证所有路径出去都是不可连接的
                }
            }
        }
    private:
        DtorAction action;
        std::thread t;    //成员变量最后声明thread
    }


# 38. 知道不同线程句柄析构行为
- std::promise：用于存储一个值，并允许另一个线程通过 std::future 获取这个值。
- std::future：用于获取由 std::promise 存储的值。

     _____           ___返回值___  std::promise _______
    |调用方|<--------|被调用方结果|<------------|被调用方|

因为被调用函数的返回值有可能在调用方执行get前就执行完毕了，所以被调用线程的返回值会保存在一个地方，所以会存在一个"共享状态"

所以在异步状态下启动的线程的共享状态的最后一个返回值是会保持阻塞的，知道该任务结束，返回值的析构函数在常规情况下，只会析构返回值的成员变量


# 39. 考虑对于单次事件通信使用void**

对于我们在线程中经常使用的flag标志位：

    while(!flag){}

可以用线程锁来代替, 这个时候等待，不会占用本该进行计算的某一个线程资源：

    bool flag(false);
    std::lock_guard<std::mutex> g(m);
    flag = true;

不过使用标志位的话也不太好，如果使用std::promise类型的对象的话就可以解决上面的问题，但是这个途径为了共享状态需要使用堆内存，而且只限于一次性通信

    std::promise<void> p;
    void react();    //反应任务
    void detect(){  //检测任务
        std::thread t([]{
            p.get_future().wait();
            react();           //在调用react之前t是暂停状态
        });
        p.set_value();  //取消暂停t
        t.join();       //把t置为unjoinable状态
    }


# 40. 对于并发使用std::atomic，对特殊内存区使用volatile**

atomic原子操作（其他线程只能看到ai的值是0 或者10）:

    std::atomic<int> ai(0);
    ai = 10;                 //将ai原子的设置为10

volatile 类型值（其他线程可以看到vi取任何值）：

    volatile int vi(0);      //将vi初始化为0
    vi = 10;                 //将vi的值设置为10，如果两个线程同时执行vi++的话，就可能会出现11和12两种情况

volatile的作用：告诉编译器正在处理的变量使用的是特殊内存，不要在这个变量上做任何优化

    volatile int x;
    auto y = x; //读取x，（这个时候auto会把const和volatile的修饰词丢弃掉，所以y的类型是int
    y = x;      //再次读取x，这个时候不会被优化掉






