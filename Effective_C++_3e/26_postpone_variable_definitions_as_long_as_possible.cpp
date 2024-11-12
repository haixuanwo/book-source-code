/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:25:58
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:36:55
 * @Description: file content
 */

/*
条款26：尽可能延后变量定义式的出现时间

在C++中，你应当尽可能延后变量的定义直到你真正需要它。这样做可以减少变量的作用域
和生命周期，增加程序的清晰度和性能，并减少由于变量过早创建而带来的资源消耗。
*/

#include <vector>

void processElement(int element) {
    // 处理元素
}

void processVector(const std::vector<int>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        int element = vec[i];  // 将变量定义放在需要的位置
        processElement(element);
    }
}
