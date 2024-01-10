/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-15 12:57:15
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-15 22:58:04
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string name("AnnaBelle");
    auto pos1 = name.find("Anna");
    cout << pos1;

    string lowercase("annabelle");
    pos1 = lowercase.find("Anna");
    cout << " " << pos1 << endl;

    return 0;
}
