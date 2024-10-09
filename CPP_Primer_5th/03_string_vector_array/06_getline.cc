/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 10:17:05
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 10:17:20
 * @Description: file content
 */

#include <string>
using std::string;
using std::getline;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string line;

    while (getline(cin, line))
    {
        cout << line << endl;
    }

    return 0;
}
