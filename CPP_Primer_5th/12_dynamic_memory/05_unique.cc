/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-19 09:16:02
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-19 09:16:15
 * @Description: file content
 *
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;

int main()
{
    shared_ptr<string> p(new string("Hello!"));
    shared_ptr<string> p2(p);
    string newval;

    if (!p.unique())
    {
        p.reset(new string(*p));
    }
    *p += newval;

    cout << *p << " " << *p2 << endl;
}
