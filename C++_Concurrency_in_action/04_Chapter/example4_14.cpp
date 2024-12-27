/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 17:22:01
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 17:23:19
 * @Description: file content
 */
#include <future>

template<typename F,typename A>
std::future<std::result_of<F(A&&)>::type>
spawn_task(F&& f, A&& a)
{
    typedef std::result_of<F(A&&)>::type result_type;
    std::packaged_task<result_type(A&&)>
        task(std::move(f));

    std::future<result_type> res(task.get_future());

    std::thread t(std::move(task), std::move(a));
    t.detach();
    return res;
}
