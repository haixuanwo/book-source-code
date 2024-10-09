/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-15 23:13:25
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-16 11:06:24
 * @Description: file content
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s = "sime string", s2 = "some other string";
    s.insert(s.begin(), s2.begin(), s2.end());
    cout << "insert iterators version: " << s << endl;

    s = "some string";
    s.insert(0, s2);
    cout << "insert string at given position: " << s << endl;

    s = "some string";
    s.insert(0, s2, 0, s2.size());
    cout << "insert positional version: " << s << endl;

    s = "";
    vector<char> c_vec(1, 'a');
    s.insert(s.begin(), c_vec.begin(), c_vec.end());
    s.insert(s.size(), 5, '!');
    cout << s << endl;

    s.erase(s.size() - 5, 5);
    cout << s << endl;


    s = "";
    const char* cp = "Stately, plump Buck";
    s.assign(cp, 7);
    cout << s << endl;
    s.insert(s.size(), cp + 7);
    cout << s << endl;

    s = "C++ Primer";
    s2 = s;
    s.insert(s.size(), " 4th Ed.");
    s2.append(" 4th Ed.");
    cout << s << " " << s2 << endl;

    // 1. insert and erase
    s.erase(11, 3);
    s.insert(11, "5th");

    // 2. use replace
    s2.replace(11, 3, "5th");
    cout << s << " " << s2 << endl;

    // 1. use replace if we know where the string we want to replace is
    s.replace(11, 3, "Fifth");

    // 2. call find first to get position from which to replace
    auto pos = s2.find("5th");
    if (pos != string::npos)
    {
        s2.replace(pos, 3, "Fifth");
    }
    else
    {
        cout << "something's wrong, s2 is: " << s2 << endl;
    }
    cout << s << " " << s2 << endl;

    return 0;
}
