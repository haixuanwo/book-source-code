/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 14:15:27
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 14:17:37
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    if (str < phrase) cout << "str is smaller" << endl;
    if (slang > str) cout << "slang is greater" << endl;
    if (slang > phrase) cout << "slang is greater" << endl;

    return 0;
}
