/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-11 18:55:30
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-11 18:55:34
 * @Description: file content
 */

#include "Sales_data.h"
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
    Sales_data data1, data2;
    std::cin >> data1 >> data2;
    cout << data1 + data2 << endl;
    cout << 42 + 5 << endl;

    data1 + data2;
    operator+(data1, data2);
    cout << operator+(data1, data2) << endl;

    data1 += data2;
    data1.operator+=(data2);
    cout << data1 << endl;

    return 0;
}
