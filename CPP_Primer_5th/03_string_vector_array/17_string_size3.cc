/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 15:18:21
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 15:18:25
 * @Description: file content
 */

#include <string>
using std::string; using std::getline;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	string line;

	// read input a line at a time and discard blank lines
	while (getline(cin, line))
		if (!line.empty())
			cout << line << endl;

	return 0;
}
