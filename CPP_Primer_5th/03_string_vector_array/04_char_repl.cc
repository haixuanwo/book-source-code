/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-09 17:25:12
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 09:45:05
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string str("some string"), orig = str;
    if (!str.empty())
        cout << str[0] << endl;

    if (!str.empty())
        str[0] = toupper(str[0]);
    cout << str << endl;

    str = orig;
    if (str.begin() != str.end())
    {
        auto it = str.begin();
        *it = toupper(*it);
    }
    cout << str << endl;

    // 1. for loop with subscripts
    str = orig;
    for (decltype(str.size()) index = 0;
        index != str.size() && !isspace(str[index]);
        ++index)
    {
        str[index] = toupper(str[index]);
    }
    cout << str << endl;

    // 2. for loop with iterators instead of subscripts
    str = orig;
    for (auto it = str.begin();
        it != str.end() && !isspace(*it);
        it++)
    {
        *it = toupper(*it);
    }
    cout << str << endl;

    // 3. while instead of a for with subscripts
    str = orig;
    decltype(str.size()) index = 0;
    while (index != str.size() && !isspace(str[index]))
    {
        str[index] = toupper(str[index]);
        ++index;
    }
    cout << str << endl;

    // 4. while loop with iterators
    auto beg = str.begin();
    while (beg != str.end() && !isspace(*beg))
    {
        *beg = toupper(*beg);
        ++beg;
    }
    cout << str << endl;

    str = orig;
    for (auto c : str)
    {
        cout << c << endl;
    }

    for (auto &c : str)
        c = '*';
    cout << str << endl;

    str = orig;

    for (decltype(str.size()) ix = 0; ix != str.size(); ix++)
        cout << str[ix] << endl;

    for (decltype(str.size()) ix = 0; ix != str.size(); ix++)
        str[ix] = '*';
    cout << str << endl;

    str = orig;
    for (auto beg = str.begin(); beg != str.end(); ++beg)
    {
        cout << *beg << endl;
    }

    for (auto beg = str.begin(); beg != str.end(); ++beg)
    {
        *beg = '*';
    }
    cout << str << endl;

    return 0;
}
