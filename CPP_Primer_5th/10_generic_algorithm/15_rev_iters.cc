/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-17 23:06:58
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-17 23:07:15
 * @Description: file content
 */

#include <vector>
using std::vector;

#include<iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    // reverse iterator of vector from back to front
    for (auto r_iter = vec.crbegin(); // binds r_iter to the last element
              r_iter != vec.crend();  // one before first element
              ++r_iter)          // decrements the iterator one element
        cout << *r_iter << endl; // prints 9, 8, 7, . . . 0
    return 0;
}
