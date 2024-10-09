/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 14:29:02
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 14:29:20
 * @Description: file content
 */

#include <iterator>
using std::begin;
using std::end;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <cstddef>
using std::size_t;

#include "Blob.h"

int main()
{
    Blob<int> ia;                // empty Blob<int>
	Blob<int> ia2 = {0,1,2,3,4}; // Blob<int> with five elements
	vector<int> v1(10, 0); // ten elements initialized to 0
    Blob<int> ia3(v1.begin(), v1.end());  // copy elements from v1
    cout << ia << "\n" << ia2 << "\n" << ia3 << endl;
}
