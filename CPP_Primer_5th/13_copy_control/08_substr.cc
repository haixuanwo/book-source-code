/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-10 12:50:55
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-10 12:56:07
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string::size_type position(const string &a, const string &b, const string &c)
{
    return (a+b).find(c);
}

int main()
{
    string s1 = "a value", s2 = "another";

    auto x = position(s1, s2, "val");
    if (x == string::npos)
    {
        cout << "not found" << endl;
    }
    else if ( x < s1.size())
    {
        cout << "value is in first paramter" << endl;
    }
    else
    {
        cout << "value is in sencond paramter" << endl;
    }

    auto n = (s1 + s2).find('a');
    cout << "n = " << n << endl;
    s1 + s2 = "wow!";
    cout << s1 + s2 << endl;
}
