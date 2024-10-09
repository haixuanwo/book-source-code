/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-19 09:36:40
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-19 09:55:20
 * @Description: file content
 */

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

int main()
{
    unique_ptr<int[]> up(new int[10]);
    for (size_t i = 0; i != 10; i++)
    {
        up[i] = i;
    }
    up.release();

    shared_ptr<int> sp(new int[10], [](int *p){ delete [] p; });
    for (size_t i = 0; i != 10; i++)
    {
        *(sp.get() + i) = i;
    }
    sp.reset();

}
