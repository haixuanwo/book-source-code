/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 14:34:47
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 14:34:51
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending :word;
}

int main()
{
    size_t cnt = 1;
    cout << make_plural(cnt, "success", "es") << endl;

    cnt = 2;
    cout << make_plural(cnt, "failure", "s") << endl;

    return 0;
}
