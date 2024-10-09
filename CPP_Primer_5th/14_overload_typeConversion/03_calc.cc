/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-11 18:47:18
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-11 18:54:01
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind;
using std::function;
using namespace std::placeholders;

int add(int i, int j)
{
    return i + j;
}

auto mod = [](int i, int j) { return i%j; };

struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator/divisor;
    }
};

int main()
{
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = [](int i, int j) { return i*j; };

    cout << f1(4, 2) << endl;
    cout << f2(4, 2) << endl;
    cout << f3(4, 2) << endl;

    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j){ return i*j; }},
        {"%", mod}
    };

    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;

    return 0;
}
