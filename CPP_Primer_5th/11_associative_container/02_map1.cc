/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 09:23:12
 * @LastEditors: Clark
 * @LastEditTime: 2024-10-09 09:47:49
 * @Description: file content
 */

#include <set>
using std::multiset;

#include <map>
using std::map;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <iostream>
using std::cout;
using std::endl;

#include "Sales_data.h"
#include "make_plural.h"

typedef bool(*SDComp)(const Sales_data&, const Sales_data&);

multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

multiset<Sales_data, SDComp> bookstore2([](const Sales_data &l, const Sales_data &r)
{
    return l.isbn() < r.isbn();
});

void show_map(const std::map<string, size_t> &m)
{
    cout << "Size of map: " << m.size() << endl;

    for (const auto &pair : m)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

int main()
{
    map<string, size_t> word_count;
    word_count["Anna"] = 1;
    cout << word_count["Anna"] << endl;

    ++word_count["Anna"];
    cout << word_count["Anna"] << endl;

    string word;
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
    show_map(word_count);

    typedef map<string, size_t>::value_type valType;
    word_count.insert(valType(word, 1));
    show_map(word_count);

    pair<map<string, size_t>::iterator, bool> insert_ret;
    insert_ret = word_count.insert({"Anna", 1});
    if (insert_ret.second == false)
    {
        insert_ret.first->second++;
    }
    cout << word_count["Anna"] << endl;

    auto map_it = word_count.begin();
    cout << map_it->first;
    cout << " " << map_it->second << endl;
    ++map_it->second;
    show_map(word_count);

    return 0;
}
