/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:22:28
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:22:32
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;
using std::showpoint;
using std::noshowpoint;

int main()
{
	cout << 10.0 << endl;         // prints 10
	cout << showpoint << 10.0     // prints 10.0000
	     << noshowpoint << endl;  // revert to default format

	cout << 10.0 << endl;  // prints 10

	return 0;
}

