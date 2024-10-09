/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 14:28:30
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 14:28:39
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

string st1;       // empty string
string st2(st1);  // st2 is a copy of st1

int main()
{
    string st("The expense of spirit\n");
    cout << "The size of " << st << "is " << st.size()
         << " characters, including the newline" << endl;
    return 0;
}
