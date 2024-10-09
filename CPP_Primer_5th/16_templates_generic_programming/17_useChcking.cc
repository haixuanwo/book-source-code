/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 16:52:48
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 16:52:52
 * @Description: file content
 */

#include "Blob.h"
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> v1(3, 43), v2(10);
	Blob<int> a1(v1.begin(), v1.end()),
	          a2 = {0,1,2,3,4,5,6,7,8,9},
	          a3(v2.begin(), v2.end());

	cout << a1 << "\n\n" << a2 << "\n\n" << a3 << endl;
	cout << "\ncopy" << "\n\n";

	Blob<int> a5(a1);
	cout << a5 << endl;
	cout << "\nassignment" << "\n\n";

    return 0;
}
