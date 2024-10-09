/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-17 13:08:23
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-17 13:16:21
 * @Description: file content
 */

#include <algorithm>
using std::copy;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::inserter;
using std::front_inserter;

void print(const string &label, const list<int> &lst)
{
    cout << label << endl;
    for (auto &iter : lst)
    {
        cout << iter << " ";
    }
    cout << endl;
}

int main()
{
    list<int> lst = {1,2,3,4};
    print("lst", lst);

    list<int> lst2, lst3;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    print("lst2", lst2);
    print("lst3", lst3);

    vector<int> v = {1,2,3,4,5};
    list<int> new_lst = {6,7,8,9};
    auto it = new_lst.begin();
    copy(v.cbegin(), v.cend(), inserter(new_lst, it));
    print("new_lst", new_lst);

    return 0;
}
