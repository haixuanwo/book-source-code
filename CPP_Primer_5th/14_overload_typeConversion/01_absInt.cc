/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-11 18:30:22
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-11 18:37:55
 * @Description: file content
 */

#include <vector>
using std::vector;

#include <iterator>
using std::inserter;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::transform;

struct absInt
{
    int operator()(int val) const
    {
        return val < 0 ? -val : val;
    }
};

int main()
{
    int i = -42;
    absInt absObj;
    unsigned ui = absObj(i);
    cout << i << " " << ui << endl;

    vector<int> vi;
    while (cin >> i)
    {
        vi.push_back(i);
    }

    vector<unsigned> vu;
    transform(vi.begin(), vi.end(), back_inserter(vu), absInt());

    for_each(vu.begin(), vu.end(), [](unsigned i){ cout << i << " "; });
    cout << endl;

    vector<unsigned> vu2;
    transform(vi.begin(), vi.end(), back_inserter(vu2),
        [](int i){ return i < 0 ? -i : i; });

    if (vu == vu2)
    {
        cout << "as expected" << endl;
    }
    else
    {
        cout << "something's wrong, vectors differ" << endl;
        for_each(vu.begin(), vu.end(), [](unsigned i){ cout << i << " "; });
    }
    cout << endl;

    return 0;
}
