/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 12:48:29
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-18 13:43:09
 * @Description: file content
 */

#include <set>
using std::set;
using std::multiset;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i)
    {
	    ivec.push_back(i);
	    ivec.push_back(i);  // duplicate copies of each number
	}

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());

    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;

    iset.find(1);
    iset.find(11);
    iset.count(1);
    iset.count(11);

    iset.find(1);
    iset.find(11);
    miset.count(1);
    miset.count(11);

    set<string> set1;
    set1.insert("the");
    set1.insert("end");

    ivec = {2,4,6,8,2,4,6,8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    set2.insert({1,3,5,7,1,3,5,7});

    return 0;
}
