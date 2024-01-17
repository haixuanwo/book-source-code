/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:05:41
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:05:46
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;
using std::oct;
using std::dec;
using std::hex;
using std::showbase;
using std::noshowbase;
using std::uppercase;
using std::nouppercase;

bool get_status()
{
	return false;
}

int main()
{
	bool b;
	cout << "default bool values: " << true << " " << false
	     << "\nalpha bool values: " << boolalpha
		 << true << " " << false << endl;

	bool bool_val = get_status();
	cout << boolalpha    // sets the internal state of cout
	     << bool_val
	     << noboolalpha; // resets the internal state to default formatting
	cout << endl;

	const int ival = 15, jval = 1024;  // const, so values never change

	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "octal: " << oct << 20 << " " << 1024 << endl;
	cout << "hex: " << hex << 20 << " " << 1024 << endl;
	cout << "decimal: " << dec << 20 << " " << 1024 << endl;


	cout << showbase;    // show the base when printing integral values
	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "in octal: " << oct  << 20 << " " << 1024 << endl;
	cout << "in hex: " << hex  << 20 << " " << 1024 << endl;
	cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
	cout << noshowbase;  // reset the state of the stream

	cout << uppercase << showbase << hex
	     << "printed in hexadecimal: " << 20 << " " << 1024
	     << nouppercase << noshowbase << dec << endl;

	return 0;
}
