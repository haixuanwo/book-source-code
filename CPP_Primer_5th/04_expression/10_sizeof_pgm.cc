/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 09:12:27
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 10:50:26
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

#include "Sales_data.h"

int main()
{
    Sales_data data, *p;

    sizeof(Sales_data);
    sizeof data;
    sizeof p;
    sizeof *p;
    sizeof data.revenue;
    sizeof Sales_data::revenue;

    cout << "short: " << sizeof(short) << "\n"
        << "short[3]: " << sizeof(short[3]) << "\n"
        << "short*: " << sizeof(short*) << "\n"
        << "short&: " << sizeof(short&) << endl; // 2
    cout << endl;

    cout << "int: " << sizeof(int) << "\n"
        << "int[3]: " << sizeof(int[3]) << "\n"
        << "int*: " << sizeof(int*) << "\n"
        << "int&: " << sizeof(int&) << endl;    // 4
    cout << endl;

    cout << "Sales_data: " << sizeof(Sales_data) << "\n"
        << "Sales_data[3]: " << sizeof(Sales_data[3]) << "\n"
        << "Sales_data*: " << sizeof(Sales_data*) << "\n"
        << "Sales_data&: " << sizeof(Sales_data&) << endl; // 48

    cout << "Sales_data::revenue: " << sizeof Sales_data::revenue << "\n"
        << "data.revernue: " << sizeof data.revenue << endl;


    int x[10];
    int *ip = x;

    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(ip)/sizeof(*ip) << endl;
    return 0;
}
