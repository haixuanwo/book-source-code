/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 14:16:55
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 14:17:48
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

template <typename T, size_t N>
void print(T (&arr)[N])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}

int main()
{
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	int a2[] = {1,3,5};
	string a3[4];

    print(a1);
    print(a2);
    print(a3);

    return 0;
}
