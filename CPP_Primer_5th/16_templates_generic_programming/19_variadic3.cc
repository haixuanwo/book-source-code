/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 17:01:45
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 17:04:04
 * @Description: file content
 */

#include <initializer_list>
using std::initializer_list;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <algorithm>
using std::min;

#include <string>
using std::string;

#include "Sales_data.h"

// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t; // no separator after the last element in the pack
}

// this version of print will be called for all but the last element in the pack

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";           // print the first argument
	return print(os, rest...); // recursive call; print the other arguments
}

template <typename T> bool bigger(const T &t, initializer_list<T> il)
{
	if (il.size() == 0)
    {
		return false;
    }

	auto b = il.begin();
    while (b != il.end())
    {
		if (t < *b)
        {
            return true;
        }
		else
        {
			++b;
        }
    }

	return false;
}

// NB: elements in the list must all have the same type
template <typename T> T min_elem(initializer_list<T> il)
{
	if (il.size() == 0)
		throw "empty";

	auto b = il.begin();      // we know there's at least one element in the list
    T ret(*b++);              // start off with the first element as the ``smallest''

    while (b != il.end())     // till we run out of elements
		ret = min(ret, *b++); // update ret if we find a smaller value

	return ret;               // return the value we found
}

// using variadic templates we can allow for conversions among the elements
// function to end the recursion, called when we have only one element left from the original pack
template<typename T> T min_elem(const T &v)
{
	return v;
}

template <typename T, typename... Back>
T min_elem(T val, Back... back)
{
	// recursive call, "pops" the first element from back, which will be val in this call
	T val2 = min_elem(back...);

	// requires that the types of val2 and val are comparable using <
	return val < val2 ? val : val2;
}

int main()
{
	// no braces, so calls variadic version of min_elem
	cout << min_elem(1.0,2,3,4.5,0.0,5,6,7,8,9) << endl;

	// calls min_element that takes a single argument
	// of type initializer_list<int>
	cout << min_elem({1,2,3,4,0,5,6,7,8,9}) << endl;

	int i = 5;
	cout << bigger(i, {1,2,3,4,0,5,6,7,8,9}) << endl;

	string s = "how now brown cow";
	print(cout, i, s, 42);  // two parameters in the pack
	print(cout, i, s);      // one parameter in the pack
	print(cout, i);         // no parameters in the pack
	cout << endl;

	return 0;
}

