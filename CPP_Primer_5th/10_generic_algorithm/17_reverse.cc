/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-17 23:20:36
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-17 23:30:23
 * @Description: file content
 */

#include <algorithm>
using std::find;
using std::find_if;
using std::for_each;
using std::remove_copy_if;
using std::reverse_copy;
using std::reverse;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v2;
    vector<int> v3 = v1;

    find(v1.begin(), v1.end(), 42);
    find_if(v1.begin(), v1.end(),
        [](int i){ return i%2; });

    reverse(v1.begin(), v1.end());
    v1 = v3;

    reverse_copy(v1.begin(), v1.end(), back_inserter(v2));
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    auto it = remove_if(v1.begin(), v1.end(),
        [](int i){ return i%2; });

    for_each(v1.begin(), it, [](int i){ cout << i << " "; });
    cout << endl;

    v1 = v3;
    v2.clear();

    remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
        [](int i){ return i%2; });

    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
