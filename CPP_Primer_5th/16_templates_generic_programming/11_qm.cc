/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 16:06:03
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 16:08:09
 * @Description: file content
 */

#include "compare.h"
#include "Blob.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

// Application.cc
// these template types must be instantiated elsewhere in the program
// instantion declaration and definition
extern template class Blob<string>;
extern template int compare(const int&, const int&);

int main()
{
	Blob<string> sa1, sa2; // instantiation will appear elsewhere

	// Blob<int> and its initializer_list constructor
	// are instantiated in this file
	Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> a2(a1);  // copy constructor instantiated in this file

	int i = compare(a1[0], a2[0]); // instantiation will appear elsewhere
    cout << "i: " << i << endl;

	return 0;
}
