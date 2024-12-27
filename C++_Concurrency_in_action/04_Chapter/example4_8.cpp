/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 16:58:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 16:58:22
 * @Description: file content
 */
#include <string>
#include <vector>
#include <future>

template<>
class packaged_task<std::string(std::vector<char>*, int)>
{
public:
    template<typename Callable>

    explicit packaged_task(Callable&& f);

    std::future<std::string> get_future();

    void operator()(std::vector<char>*, int);
};
