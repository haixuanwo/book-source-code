/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 12:41:46
 * @LastEditors: Clark
 * @LastEditTime: 2024-10-09 10:06:38
 * @Description: file content
 */

#include <map>
using std::map;

#include <set>
using std::set;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    map<string, size_t> word_count; // empty map from string to size_t
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
	                       "the", "but", "and", "or", "an", "a"};

    string word;
    while (cin >> word)
    {
        if (exclude.find(word) != exclude.end())
        {
            ++word_count[word];
        }
    }

    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times " : " time") << endl;
    }

    return 0;
}
