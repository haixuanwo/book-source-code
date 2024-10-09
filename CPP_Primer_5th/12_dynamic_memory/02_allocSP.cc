/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 23:54:35
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-18 23:54:46
 * @Description: file content
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include "Foo.h"

shared_ptr<Foo> factory(T arg)
{
    return make_shared<Foo>(arg);
}

shared_ptr<Foo> use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);
    print(cout, *p);
    cout << endl;
    return p;
}

int main()
{
    T arg;
    while (cin >> arg)
    {
        use_factory(arg);
    }
}
