/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-16 16:43:17
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-16 16:52:37
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
using std::for_each;
using std::transform;

int main()
{
    vector<int> vi;
    int i;

    while (cin >> i)
    {
        vi.push_back(i);
    }

    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " "; });
    cout << endl;

    vector<int> orig = vi;
    // replace negative values by thie absolute value
    transform(vi.begin(), vi.end(), vi.begin(),
        [](int i){ return i < 0 ? -i : i; });

    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " "; });
    cout << endl;

    vi = orig;
    transform(vi.begin(), vi.end(), vi.begin(),
        [](int i){ if (i < 0) return -i; else return i; });

    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " "; });
    cout << endl;

    return 0;
}
