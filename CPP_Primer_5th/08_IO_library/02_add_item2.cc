/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-13 17:00:20
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-14 17:34:05
 * @Description: file content
 */

#include "Sales_data.h"
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data data1, data2;

    if (read(cin, data1) && read(cin, data2))
    {
        if (data1.isbn() == data2.isbn())
        {
            Sales_data sum = add(data1, data2);
            print(cout, sum);
            cout << endl;
        }
    }
    else
    {
        cerr << "Input failed!" << endl;
    }

    return 0;
}
