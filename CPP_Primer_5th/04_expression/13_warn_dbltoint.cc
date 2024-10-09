/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 11:02:17
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 11:02:25
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// the compiler might warn about loss of precision
	int ival = 3.541 + 3; // the compiler might warn about loss of precision
	cout << ival << endl;  // prints 6

	return 0;
}
