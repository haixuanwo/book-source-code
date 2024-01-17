/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-18 00:17:02
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-18 00:17:06
 * @Description: file content
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::find_if;

#include <functional>
using std::bind;
using std::placeholders::_1;

int main()
{
    vector<string> svec = {"hi", "bye"};
    // bind each string in the range to the implicit first argument to empty
    auto it = find_if(svec.begin(), svec.end(),
	                  bind(&string::empty, _1));
    if (it == svec.end())
		cout << "worked" << endl;
	else
		cout << "failed"  << endl;

    auto f =  bind(&string::empty, _1);

    cout << f(*svec.begin()) << endl; // ok: argument is a string f will use .* to call empty
	cout << f(&svec[0]) << endl; // ok: argument is a pointer to string f will use .-> to call empty
}
