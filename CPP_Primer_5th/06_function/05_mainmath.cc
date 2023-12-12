/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 13:54:18
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 13:54:26
 * @Description: file content
 */

#include "LocalMath.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// pass a literal to fact
    int f = fact(5);  // f equals 120, i.e., the result of fact(5)
	cout << "5! is " << f << endl;

    // call fact on i and print the result
	int i = 5;
    int j = fact(i);
	cout << i << "! is " << j << endl;

	// call fact on a const int
    const int ci = 3;
    int k = fact(ci);
	cout << ci << "! is " << k << endl;

    return 0;
}
