/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 17:27:03
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 17:28:17
 * @Description: file content
 */
#include <experimental/future>

template<typename Func>
std::experimental::future<decltype(std::declval<Func>()())>
spawn_async(Func&& func){
    std::experimental::promise<
        decltype(std::declval<Func>()())> p;

    auto res=p.get_future();
    std::thread t(
        [p=std::move(p),f=std::decay_t<Func>(func)]() mutable {
            try
            {
                p.set_value_at_thread_exit(f());
            }
            catch(...)
            {
                p.set_exception_at_thread_exit(std::current_exception());
            }
    });

    t.detach();
    return res;
}
