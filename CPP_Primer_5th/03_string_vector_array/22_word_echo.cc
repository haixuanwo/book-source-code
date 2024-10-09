/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 16:02:29
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 16:02:35
 * @Description: file content
 */

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
	string word;
	while (cin >> word)       // read until end-of-file
		cout << word << endl; // write each word followed by a new line
	return 0;
}
