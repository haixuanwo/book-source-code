/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 23:59:25
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-19 00:05:50
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

#include <new>
using std::nothrow;

size_t get_size()
{
    return 42;
}

int main()
{
    int *p1 = new int;
    int *p2 = new (nothrow)int;

    int i0;
    int *p0 = new int;
    delete p0;

    int i(1024);
    string s(10, '9');
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    int *pi = new int(1024);
    string *ps = new string(10, '9');
    vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};

    cout << "*pi: " << *pi
        << "\ti: " << i << endl
        << "*ps: " << *ps
        << "\ts: " << s << endl;

    for (auto b = pv->begin(); b != pv->end(); ++b)
    {
        cout << *b << " ";
    }
    cout << endl;

    delete pi;
    delete ps;
    delete pv;

    int *pia = new int[get_size()];
    delete [] pia;
    typedef int arrT[42];
    int *p = new arrT;
    delete [] p;

    return 0;
}
