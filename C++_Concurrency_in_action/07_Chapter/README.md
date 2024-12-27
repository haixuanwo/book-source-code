
# listing_7_1.cpp
std::atomic_flag flag;
flag.test_and_set(std::memory_order_acquire)
flag.clear(std::memory_order_release);

# listing_7_2.cpp
lock_free_stack
std::atomic<node*> head;

# listing_7_3.cpp
lock_free_stack
std::shared_ptr<T> data;

# listing_7_4.cpp
lock_free_stack
std::atomic<unsigned> threads_in_pop;

# listing_7_5.cpp
lock_free_stack
std::atomic<node*> to_be_deleted;

# listing_7_6.cpp
std::atomic<void*>& hp

# listing_7_7.cpp
std::atomic<std::thread::id> id;
std::atomic<void*> pointer;

# listing_7_8.cpp
std::atomic
std::function<void(void*)> deleter;

# listing_7_9.cpp
lock_free_stack

# listing_7_10.cpp
std::shared_ptr<T> data;
std::experimental::atomic_shared_ptr<node> next;

# listing_7_11.cpp
lock_free_stack

# listing_7_12.cpp
lock_free_stack
std::atomic<counted_node_ptr> head;

# listing_7_13.cpp
lock_free_stack
std::shared_ptr<T> data;
std::atomic<int> internal_count;

# listing_7_14.cpp
lock_free_queue
std::atomic<node*> head;
std::atomic<node*> tail;

# listing_7_15.cpp
push

# listing_7_16.cpp
lock_free_queue
std::atomic<counted_node_ptr> head;
std::atomic<counted_node_ptr> tail;

# listing_7_17.cpp
lock_free_queue
pop

# listing_7_18.cpp
lock_free_queue

# listing_7_19.cpp
lock_free_queue
free_external_counter

# listing_7_20.cpp
lock_free_queue
free_external_counter

# listing_7_21.cpp
lock_free_queue
pop

# listing_7_22.cpp
lock_free_queue
set_new_tail
push
