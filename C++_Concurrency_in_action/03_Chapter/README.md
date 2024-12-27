
# example3_1.cpp
std::mutex some_mutex;
std::lock_guard<std::mutex> lock(some_mutex);
std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();

# example3_2.cpp
data_wrapper
std::lock_guard<std::mutex> lock(mtx);

# example3_3.cpp
stack
bool empty() const;
size_t size() const;
T& top();
T const& top() const;
void push(T const&);
void push(T&&);
void pop();
void swap(stack&&);

# example3_4.cpp
threadsafe_stack

# example3_5.cpp
std::stack<T> data;
mutable std::mutex m;
std::lock_guard<std::mutex> lock(m);

# example3_6.cpp
std::lock(lhs.m,rhs.m);
std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);

# example3_7.cpp
hierarchical_mutex
void lock()
void unlock()

# example3_8.cpp
hierarchical_mutex
std::mutex internal_mutex;
internal_mutex.lock();
internal_mutex.unlock();

# example3_9.cpp
std::unique_lock<std::mutex> lock_a(lhs.m,std::defer_lock);
std::unique_lock<std::mutex> lock_b(rhs.m,std::defer_lock);
std::lock(lock_a,lock_b);

# example3_10.cpp
mutable std::mutex m;
std::lock_guard<std::mutex> lock_a(m);

# example3_11.cpp
std::shared_ptr
std::mutex

# example3_12.cpp
std::once_flag
std::call_once
一起配合使用，用于确保某个函数在多线程环境下只被调用一次

# example3_13.cpp
std::shared_lock<std::shared_mutex> lk(entry_mutex)
std::lock_guard<std::shared_mutex> lk(entry_mutex)
