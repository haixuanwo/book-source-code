/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 16:11:26
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 16:11:31
 * @Description: file content
 */

#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int ia[] = {0,1,2,3,4,5,6,7,8,9};

int main()
{
   // sizeof(ia)/sizeof(*ia) returns the number of elements in ia
   constexpr size_t sz = sizeof(ia)/sizeof(*ia);

   int arr2[sz];  // ok sizeof returns a constant expression

   cout << "ia size: " << sz << endl;

   return 0;
}

