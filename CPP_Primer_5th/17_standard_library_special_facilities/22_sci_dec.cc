/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:43:14
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:43:18
 * @Description: file content
 */

#include <cmath>
using std::sqrt;

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::scientific;
using std::uppercase;
using std::nouppercase;

#include "Version_test.h"
#ifdef HEX_MANIPS
using std::hexfloat;
using std::defaultfloat;
#endif

int main()
{
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		 << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
	     << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
#ifdef HEX_MANIPS     // no workaround for this missing manipulator
		 << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
#endif
		 << "use defaults: " << defaultfloat << 100 * sqrt(2.0)
		 << "\n\n";

	cout << uppercase
	     << "scientific: " << scientific << sqrt(2.0) << '\n'
	     << "fixed decimal: " << fixed << sqrt(2.0) << '\n'
#ifdef HEX_MANIPS     // no workaround for this missing manipulator
		 << "hexadecimal: " << hexfloat << sqrt(2.0) << "\n\n"
#endif
		 << nouppercase;

	return 0;
}
