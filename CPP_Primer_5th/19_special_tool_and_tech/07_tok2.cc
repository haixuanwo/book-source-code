/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-18 00:29:57
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-18 00:30:01
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "Token.h"

int main()
{
	Token token;
	Token t2;
	Token t3;
	cout << t2 << " " << t3 << endl;
	t2 = string("hi mom!");
	t3 = "good bye";
	token = t2;
	token = "boo";
	cout << token << endl;
	t2 = t3;
	cout << t2 << endl;

	token = 42;
	cout << token << endl;
}

