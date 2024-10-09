/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 23:47:14
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-18 23:47:27
 * @Description: file content
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include "Foo.h"

Foo* factory(T arg)
{
    return new Foo(arg);
}

Foo* use_factory(T arg)
{
    Foo *p = factory(arg);
    print(cout, *p);
    cout << endl;

    return p;
}

int main()
{
    T arg;
    while (cin >> arg)
    {
        auto p = use_factory(arg);
        delete p;
    }

    return 0;
}
