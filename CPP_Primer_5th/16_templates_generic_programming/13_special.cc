/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 16:14:20
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 16:14:24
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

// declarations before definitions
template <typename T> void f(T);
template <typename T> void f(const T*);

template <typename T> void g(T);
template <typename T> void g(T*);

// definitions
template <typename T> void f(T) { cout << "f(T)" << endl; }
template <typename T> void f(const T*)
{ cout << "f(const T*)" << endl; }

template <typename T> void g(T) { cout << "g(T)" << endl; }
template <typename T> void g(T*) { cout << "g(T*)" << endl; }

int main()
{
	int i = 42;
	f(i);  // calls f(T), f(const T*) isn't viable

	f(&i); // calls f(T), which is an exact match,
	       // f(const T*) requires a conversion

	g(i);  // calls g(T), g(T*) isn't viable
	g(&i); // calls g(T*), both templates are viable,
	       // but g(T*) is more specialized

	int *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);   g(p);   g(ci);   g(p2);
	f(42);   f(p);   f(ci);   f(p2);

	return 0;
}
