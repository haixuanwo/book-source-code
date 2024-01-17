/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 15:48:26
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 15:57:49
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <unordered_set>
using std::unordered_multiset;

#include <functional>
#include "Sales_data.h"
using std::hash;

int main()
{
	// uses hash<Sales_data> and Sales_data operator==

    unordered_multiset<Sales_data> SDset;
	Sales_data item;

	while (cin >> item) {
		SDset.insert(item);
	}
	cout << SDset.size() << endl;

	return 0;
}
