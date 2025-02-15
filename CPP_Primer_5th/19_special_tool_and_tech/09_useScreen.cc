/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-18 00:32:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-18 00:32:57
 * @Description: file content
 */

#include "Screen.h"

#include <functional>
using std::function;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

struct X
{
	int foo(int i)
    {
        cout << "foo(" << i << ")" << endl;
        return i;
    }
};

void xfcn()
{
	function<int (X*, int)> f;
	f = &X::foo;		// pointer to member

	X x;
	int v = f(&x, 5);
	cout << "v = " << v << endl;
}

int main ()
{
	// pdata can point to a string member of a const (or nonconst) Screen
	const string Screen::*pdata;  // uninitialized
	pdata = &Screen::contents;    // points to the contents member
	auto pdata2 = &Screen::contents; // equivalent declaration

	// data() returns a pointer to the contents member of class Screen
	const string Screen::*pdata3 = Screen::data();

	// Screen objects
	Screen myScreen, *pScreen = &myScreen;
	const Screen cScreen, *pcScreen = &cScreen;

	// .* dereferences pdata to fetch the contents member
	// from the object myScreen
	auto str = myScreen.*pdata;  // s is a string
	auto cstr = cScreen.*pdata;  // c is a const string

	// ->* dereferences pdata to fetch contents
	// from the object to which pScreen points
	str = pScreen->*pdata;

	// pmf is a pointer that can point to a Screen member function
	// that takes no arguments, returns a char, and is const
	// that returns a char and takes no arguments
	auto pmf = &Screen::get_cursor;
	char (Screen::*pmf2)() const = &Screen::get; // same type as pmf

	pmf = &Screen::get; // which version of get deduced from type of pmf
	pmf2 = &Screen::get_cursor;

	Screen s;
	char c1 = s.get_cursor(); // gets character at the cursor directly
	char c2 = (s.*pmf2)();    // calls get_cursor indirectly through pmf2

	// call the function to which pmf points
	// on the object to which pScreen points
	c1 = (pScreen->*pmf)();

	// pmf3 points to the two-parameter version of get
	char (Screen::*pmf3)(Screen::pos, Screen::pos) const = &Screen::get;
	c1 = myScreen.get(0,0);     // call two-parameter version of get
	c2 = (myScreen.*pmf3)(0,0); // equivalent call to get

	// Op is a type that can point to a member function of Screen
	// that returns a char and takes two pos arguments
	using Op = char (Screen::*)(Screen::pos, Screen::pos) const;
	// equivalent declaration of Op using a typedef
	typedef char (Screen::*Op)(Screen::pos, Screen::pos) const;

	Op get = &Screen::get; // get points to the get member of Screen

	myScreen.move(Screen::HOME);  // invokes myScreen.home
	myScreen.move(Screen::DOWN);  // invokes myScreen.down

	// bind an object of type function to a pointer to member
	function<char (const Screen*)> f = &Screen::get_cursor;

	return 0;
}

