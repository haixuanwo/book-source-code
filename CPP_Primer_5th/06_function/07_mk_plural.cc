/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 13:58:23
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 13:58:36
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include "make_plural.h"

int main()
{
	size_t cnt = 1;
	cout << make_plural(cnt, "success", "es") << endl;

	cnt = 2;
	cout << make_plural(cnt, "failure", "s") << endl;

	return 0;
}
