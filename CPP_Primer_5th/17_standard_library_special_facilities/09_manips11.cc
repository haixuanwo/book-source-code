/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:07:31
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:07:49
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

#include "Version_test.h"
#ifdef HEX_MANIPS
using std::hexfloat;
using std::defaultfloat;
#endif

int main()
{
	double pi = 3.14;
	cout << pi << " "
#ifdef HEX_MANIPS
	     << hexfloat << pi    // no workaround for this missing manipulator
#endif
	     << defaultfloat << " " << pi << endl;

	return 0;
}

