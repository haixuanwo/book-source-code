/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-14 17:45:45
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-10 12:32:30
 * @Description: file content
 */

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

void process(ifstream &is)
{
    string s;

    while (is >> s)
    {
        cout << s << endl;
    }
}

int main(int argc, char *argv[])
{
    for (auto p = argv+1; p != argv + argc; ++p)
    {
        ifstream input(*p);
        if (input)
        {
            process(input);
        }
        else
        {
            cerr << "couldn't open: " + string(*p);
        }
    }


    auto p = argv + 1, end = argv + argc;
    ifstream input;
    while (p != end)
    {
        input.open(*p);
        if (input)
        {
            process(input);
        }
        else
        {
            cerr << "couldn't open: " + string(*p);
        }

        input.close();
        ++p;
    }

}
