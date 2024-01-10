/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-17 20:57:36
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-17 21:07:05
 * @Description: file content
 */

#include <algorithm>
using std::copy;
using std::sort;
using std::unique_copy;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <fstream>
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main()
{
    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof;
    vector<int> v(int_it, int_eof);

    sort(v.begin(), v.end());
    ostream_iterator<int> out(cout, " ");
    unique_copy(v.begin(), v.end(), out);
    cout << endl;

    ofstream out_file("10_generic_algorithm/data/outFile3");
    ostream_iterator<int> out_iter(out_file, " ");
    copy(v.begin(), v.end(), out_iter);
    out_file << endl;

    return 0;
}
