
# example4_1.cpp
std::mutex
std::queue
std::condition_variable: notify_one(), wait(lk,[&]{return isEmpty;})

# example4_2.cpp
queue
swap
empty
size
front
back
push
pop

# example4_3.cpp
threadsafe_queue

# example4_4.cpp
threadsafe_queue
std::mutex
std::queue<T>
std::condition_variable

# example4_5.cpp
threadsafe_queue

# example4_6.cpp
threadsafe_queue
std::future<int> the_answer=std::async(find_the_answer_to_ltuae);

# example4_7.cpp
std::async

# example4_8.cpp
std::future

# example4_9.cpp
std::packaged_task<void()> task;
std::packaged_task是 C++ 11 引入的一个类模板，它的主要功能是将一个可调用
对象（如函数、lambda 表达式、函数对象等）包装成一个异步任务，使得该任务可以
在一个独立的线程中执行，并可以获取其返回结果

# example4_10.cpp
std::promise

# example4_11.cpp
std::unique_lock<std::mutex> lk(m);
std::condition_variable cv;
cv.wait_until(lk,timeout)==std::cv_status::timeout
cv.notify_one();

# example4_12.cpp
std::list<T> result;
result.splice
std::partition

# example4_13.cpp
parallel_quick_sort

# example4_14.cpp
std::future<std::result_of<F(A&&)>::type>
std::packaged_task

# example4_15.cpp
atm

# example4_16.cpp
void atm::getting_pin()

# example4_17.cpp
std::experimental::future<decltype(std::declval<Func>()())>
std::experimental::promise<decltype(std::declval<Func>()())> p;

# example4_18.cpp
void process_login(std::string const& username,std::string const& password)

# example4_19.cpp
std::future<void> process_login(std::string const& username, std::string const& password)

# example4_20.cpp
std::experimental::future<void> process_login(
    std::string const& username,std::string const& password)

# example4_21.cpp
process_login

# example4_22.cpp
std::future<FinalResult> process_data(std::vector<MyData>& vec)

# example4_23.cpp
std::experimental::future<FinalResult> process_data(std::vector<MyData>& vec)

# example4_24.cpp
find_and_process_value

# example4_25.cpp
void foo()

# example4_26.cpp
void process_data(data_source &source, data_sink &sink)

# example4_27.cpp
void process_data(data_source &source, data_sink &sink)
