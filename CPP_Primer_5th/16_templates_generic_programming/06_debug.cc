/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 15:15:46
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 15:18:42
 * @Description: file content
 */

#include "debug_rep.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9};
	string s("hi");
	cout << debug_rep(v) << endl;
	cout << debug_rep(s) << endl;
	cout << debug_rep("hi") << endl;
	cout << debug_rep(&v[0]) << endl;
	cout << debug_rep(&s) << endl;

	const string *sp = &s;
	cout << debug_rep(sp) << endl;

    char carr[] = "bye";            // calls pointer version if no overloads
	cout << debug_rep(carr) << endl;
	vector<string> authors = {"Proust", "Shakespeare", "Barth"};
	vector<const char*> authors2 = {"Proust", "Shakespeare", "Barth"};
	cout << debug_rep(authors) << endl;
	cout << debug_rep(authors2) << endl;
	cout << debug_rep(s) << endl;
	s += "more stuff";
	cout << debug_rep(s) << endl;
	s += "\\escape\"and quotes";
	cout << debug_rep(s) << endl;

	cout << debug_rep("hi world!") << endl; // calls debug_rep(T*)

	s = "hi";
	const char *cp = "bye";
	char arr[] = "world";

	cout << debug_rep(s) << endl;  // calls specialization debug_rep(const string&
	cout << debug_rep(cp) << endl; // calls specialization debug_rep(const char*
	cout << debug_rep(arr) << endl;// calls specialization debug_rep(char*
	cout << debug_rep(&s) << endl; // calls template debug_rep(T*)

    return 0;
}
