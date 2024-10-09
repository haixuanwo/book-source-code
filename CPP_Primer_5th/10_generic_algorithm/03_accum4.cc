/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-16 17:11:10
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-16 17:11:15
 * @Description: file conten
 *
 */

#include <numeric>
using std::accumulate;

#include <iterator>
using std::istream_iterator;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0) << endl;
    return 0;
}

