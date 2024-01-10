/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-14 17:38:28
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-14 17:43:51
 * @Description: file content
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

void read()
{
    // turn on both fail and bad bits
    cin.setstate(cin.badbit | cin.eofbit | cin.failbit);
}

void off()
{
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
}

int main()
{
    cout << "before read" << endl;
    if (cin.good()) cout << "cin's good" << endl;
    if (cin.bad()) cout << "cin's bad" << endl;
    if (cin.fail()) cout << "cin's fail" << endl;
    if (cin.eof()) cout << "cin's eof" << endl;

    read();
    cout << "after read" << endl;
    if (cin.good()) cout << "cin's good" << endl;
    if (cin.bad()) cout << "cin's bad" << endl;
    if (cin.fail()) cout << "cin's fail" << endl;
    if (cin.eof()) cout << "cin's eof" << endl;

    off();
    cout << "after off" << endl;
    if (cin.good()) cout << "cin's good" << endl;
    if (cin.bad()) cout << "cin's bad" << endl;
    if (cin.fail()) cout << "cin's fail" << endl;
    if (cin.eof()) cout << "cin's eof" << endl;

    return 0;
}
