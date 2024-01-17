/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-13 23:23:52
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-13 23:27:05
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

struct Base
{
    Base() : mem(0)
    {

    }

protected:
    int mem;
};

struct Derived : Base
{
    Derived(int i) : mem(i)
    {

    }

    int get_mem()
    {
        return mem;
    }

    int get_base_mem()
    {
        return Base::mem;
    }

protected:
    int mem;
};

int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;
    cout << d.get_base_mem() << endl;
}
