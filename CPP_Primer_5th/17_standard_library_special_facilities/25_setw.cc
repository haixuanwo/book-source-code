/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:55:56
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:56:48
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::internal;

#include <iomanip>
using std::setw;
using std::setfill;

int main()
{
	int i = -16;
	double d = 3.14159;

	// pad the first column to use a minimum of 12 positions in the output
	cout << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';

	// pad the first column and left-justify all columns
	cout << left
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << right;           // restore normal justification

	// pad the first column and right-justify all columns
	cout << right
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';

	// pad the first column but put the padding internal to the field
	cout << internal
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';

	// pad the first column, using # as the pad character
	cout << setfill('#')
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << setfill(' ');   // restore the normal pad character

	return 0;
}
