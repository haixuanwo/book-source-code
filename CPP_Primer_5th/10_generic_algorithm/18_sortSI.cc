/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-17 23:31:57
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-17 23:32:06
 * @Description: file content
 */

#include <algorithm>
using std::sort;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Sales_item.h"

int main()
{
    Sales_item trans;
    vector<Sales_item> file;

    while (std::cin >> trans)
    {
        file.push_back(trans);
    }

    for (auto i : file)
    {
        cout << i << endl;
    }
    cout << "\n\n";

    sort(file.begin(), file.end(), compareIsbn);
    for (auto i : file)
    {
        cout << i << endl;
    }

    return 0;
}
