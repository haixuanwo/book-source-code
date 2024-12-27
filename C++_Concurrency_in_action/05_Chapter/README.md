
# example5_1.cpp
std::atomic_flag flag;
flag.test_and_set(std::memory_order_acquire)
flag.clear(std::memory_order_release);

# example5_2.cpp
std::atomic_bool data_ready(false);
data_ready.load()

# example5_3.cpp
get_num

# example5_4.cpp
std::atomic<bool> x,y;
std::atomic<int> z;
x.store(true,std::memory_order_seq_cst)
y.load(std::memory_order_seq_cst)

# example5_5.cpp
std::atomic<bool> x,y;
std::atomic<int> z;

# example5_6.cpp
std::atomic<int> x(0),y(0),z(0);
std::atomic<bool> go(false);

# example5_7.cpp
std::atomic<bool> x,y;
std::atomic<int> z;

# example5_8.cpp
std::atomic<bool> x,y;
std::atomic<int> z;

# example5_9.cpp
std::atomic<int> data[5];
std::atomic<bool> sync1(false),sync2(false);

# example5_10.cpp
std::atomic<X*> p;
std::atomic<int> a;

# example5_11.cpp
std::atomic<int> count;

# example5_12.cpp
std::atomic<bool> x,y;
std::atomic<int> z;
std::atomic_thread_fence(std::memory_order_release);

# example5_13.cpp
std::atomic<int> z;
std::atomic_thread_fence(std::memory_order_release);
