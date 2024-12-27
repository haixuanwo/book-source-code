
# listing_8_1.cpp
sorter
struct chunk_to_sort
{
    std::list<T> data;
    std::promise<std::list<T> > promise;
};

thread_safe_stack<chunk_to_sort> chunks;
std::vector<std::thread> threads;
std::atomic<bool> end_of_data;

void try_sort_chunk()
std::list<T> do_sort(std::list<T>& chunk_data)
void sort_chunk(boost::shared_ptr<chunk_to_sort > const& chunk)
void sort_thread()
std::list<T> parallel_quick_sort(std::list<T> input)

#  listing_8_2.cpp
T parallel_accumulate(Iterator first,Iterator last,T init)

#  listing_8_3.cpp
struct accumulate_block

#  listing_8_4.cpp
T parallel_accumulate(Iterator first,Iterator last,T init)

#  listing_8_5.cpp
T parallel_accumulate(Iterator first,Iterator last,T init)

#  listing_8_6.cpp
void gui_thread()
void task()
void process(event_data const& event)

# listing_8_7.cpp
void parallel_for_each(Iterator first,Iterator last,Func f)

# listing_8_8.cpp
void parallel_for_each(Iterator first,Iterator last,Func f)

# listing_8_9.cpp
Iterator parallel_find(Iterator first, Iterator last, MatchType match)

# listing_8_10.cpp
Iterator parallel_find(Iterator first,Iterator last,MatchType match)

# listing_8_11.cpp
void parallel_partial_sum(Iterator first,Iterator last)

# listing_8_12.cpp
barrier

# listing_8_13.cpp
barrier
