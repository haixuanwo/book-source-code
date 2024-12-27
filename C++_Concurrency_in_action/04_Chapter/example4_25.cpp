/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 18:40:37
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 18:40:59
 * @Description: file content
 */

void foo()
{
    unsigned const thread_count=...;
    latch done(thread_count);
    my_data data[thread_count];

    std::vector<std::future<void> > threads;
    for(unsigned i=0;i<thread_count;++i)
        threads.push_back(std::async(std::launch::async,[&,i]{
            data[i]=make_data(i);
            done.count_down();
            do_more_stuff();
        }));
    done.wait();
    process_data(data, thread_count);
}
