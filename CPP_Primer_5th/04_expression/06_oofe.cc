/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 16:19:04
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 16:19:17
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::toupper;

// chapter 6 will explain functions
// tolower and toupper change the argument itself, not a local copy
string &tolower(string &s)
{
	for (auto &i : s)
		i = tolower(i);
	return s;
}

string &toupper(string &s)
{
	for (auto &i : s)
		i = toupper(i);
	return s;
}

int main()
{
	int i = 0;
	cout << i << " " << ++i << endl;  // undefined

	string s("a string"), orig = s;
	cout << toupper(s) << endl;  // changes s to  uppercase
	cout << tolower(s) << endl;  // changes s to lowercase

	s = orig;
	// the calls to toupper and tolower change the value of s
	// << doesn't guarantee order of evaluation,
	// so this expression is undefined
	cout << toupper(s) << " " << tolower(s) << endl;

	string first = toupper(s);  // we control the order of evaluation
	string second = tolower(s); // by storing the results in the order in which we want

	cout << first << " " << second << endl;  // one possible evaluation
	cout << second << " " << first << endl;  // equally legal evaluation!
	cout << first << " " << first << endl;   // another legal evaluation!
	cout << second << " " << second << endl; // and a fourth!

	return 0;
}
