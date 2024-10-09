/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-11 18:41:59
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-11 18:43:06
 * @Description: file content
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_data.h"
#include "../Sales_item.h"

int main()
{
    Sales_item item1, item2;
    cin >> item1 >> item2;
    cout << item1 + item2 << endl;

    return 0;
}
