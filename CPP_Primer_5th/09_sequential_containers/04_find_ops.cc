/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-14 22:27:31
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-14 22:27:36
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string numbers("0123456789"), name("r2d2");
    auto pos = name.find_first_of(numbers); // the index of the first digit in name
    if (pos != string::npos)
    {
        cout << "found number at index: " << pos
            << " element is " << name[pos] << endl;
    }
    else
    {
        cout << "no number in: " << name << endl;
    }

    pos = 0;
    while ((pos = name.find_first_of(numbers, pos))
        != string::npos)
    {
        cout << "found number at index: " << pos
            << " element is " << name[pos] << endl;

        ++pos;
    }

    string river("Mississippi");
    auto first_pos = river.find("is");
    auto last_pos = river.rfind("is");
    cout << "find returned: " << first_pos
        << " rfind returned: " << last_pos << endl;

    string dept("03714p3");
    pos = dept.find_first_not_of(numbers);
    cout << "first_not returned: " << pos << endl;

    return 0;
}
