/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 16:25:18
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 16:38:02
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

#include <type_traits>
using std::remove_reference;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Blob.h"

// auto as function return type indicates we're using a trailing return type
// function that returns a reference to an element in the range
template <typename It>
auto reffcn(It beg, It end) -> decltype(*beg)
{
    // process the range
    return *beg;  // return a copy of an element from the range
}

// function that returns an element in the range by value
// must use typename to use a type member of a template parameter
template <typename It>
auto valfcn(It beg, It end) ->
	typename remove_reference<decltype(*beg)>::type
{
    // process the range
    return *beg;  // return a copy of an element from the range
}

int main()
{
	vector<int> vi = {1,2,3,4,5};
	Blob<string> ca = {"hi", "bye"};

	auto &i = reffcn(vi.begin(), vi.end()); // reffcn should return int&
	auto &s = reffcn(ca.begin(), ca.end()); // reffcn should return string&

	vi = {1,2,3,4};
	for (auto i : vi)
    {
        cout << i << " ";
        cout << endl;
    }

	auto &ref = reffcn(vi.begin(), vi.end());  // ref is int&
	ref = 5; // changes the value of *beg to which ref refers
	for (auto i : vi)
    {
        cout << i << " ";
        cout << endl;
    }

	auto val = valfcn(vi.begin(), vi.end()); // val is int
	cout << val << endl;  // will print 5

	return 0;
}
