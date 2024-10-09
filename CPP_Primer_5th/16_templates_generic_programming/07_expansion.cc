/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 15:41:22
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 15:44:17
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T accum(const T &t)
{
	return t;
}

template <typename T, typename... Args>
T accum(const T &t, Args... args)
{
	return t + accum(args...);
}

// h adds its variadic arguments to the starting value of 42
int h()
{
	return 42; // starting point for the accumulation
}

template <typename ...Args> int h(int t, Args ... args)
{
	return t + h(args...); // sum of all the values in args plus 42
}

// produces the sum of up to 4 integral values
void f(int i, int j = 0, int k = 0, int l = 0)
{
	cout << i << " + "
	     << j << " + "
	     << k << " + "
	     << l << " =  "
	     << i + j + k + l << endl;
}

// expansion: applies the pattern to each member of the pack
//            using a separator appropriate to the context
template<typename ... Args> void g(Args ... args)
{
	cout << sizeof...(Args) << endl;  // number of type parameters
	cout << sizeof...(args) << endl;  // number of function parameters
	// call f passing it the arguments from args
	f(args...);                // f(a1, a2, a3, ..., an)

	// call h passing it the arguments from args
	cout << h(args...) << endl; // h(a1, a2, a3, ..., an)

	// the pattern is h(x),
	// the expansion calls h on each argument in args
	f(h(args) ...);            // f(h(a1), h(a2), h(a3), ..., h(an))

	// args is expanded in the call to h
	f(h(args ...));            // f(h(a1, a2, a3, ..., an2)

	// pattern adds the argument value to result from calling h(5,6,7,8)
	f(h(5,6,7,8 ) + args ...); // f(h(5,6,7,8) + a1, h(5,6,7,8) + a2,
	                           //   h(5,6,7,8) + a3, ..., h(5,6,7,8) + an)
}

int main()
{
	cout << accum(1,2,3,4) << endl;
	g(1,2,3,4);

	return 0;
}
