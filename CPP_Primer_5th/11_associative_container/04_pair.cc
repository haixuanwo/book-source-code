/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 11:58:19
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-18 12:39:35
 * @Description: file content
 */

#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <utility>
using std::pair;
using std::make_pair;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_data.h"

pair<string, string> anon;       // holds two strings
pair<string, size_t> word_count; // holds a string and an size_t
pair<string, vector<int>> line;  // holds string and vector<int>

pair<string, string> author{"James", "Joyce"};

typedef pair<string, string> Author;
Author proust("Marcel", "Proust");  // construct a pair
Author joyce{"James", "Joyce"};     // list initialize a pair
Author austen = make_pair("Jane", "Austen"); // use make_pair

void preliminaries(vector<string> &v)
{
	// process v
	istream_iterator<string> input(cin), eof;
	copy(input, eof, back_inserter(v));
	sort(v.begin(), v.end(),
	     [](const string &a, const string &b)
	     { return a.size() < b.size(); });
}

// 1. list initialize the return value
pair<string, int> process(vector<string> &v)
{
	if (!v.empty())
		return {v.back(), v.back().size()}; // list initialize
	else
		return pair<string, int>(); // explicitly constructed return value
}

// 2. use make_pair to generate the return value
pair<string, int> process2(vector<string> &v)
{
	// process v
	if (!v.empty())
		return make_pair(v.back(), v.back().size());
	else
		return pair<string, int>();
}

// 3. explicitly construct the return value
pair<string, int> process3(vector<string> &v)
{
	// process v
	if (!v.empty())
		return pair<string, int>(v.back(), v.back().size());
	else
		return pair<string, int>();
}

int main()
{
	vector<string> v;
	string s;
	while (cin >> s)
		v.push_back(s);

	preliminaries(v);  // sort v into size order

	// all three output statements should be the same
	auto biggest = process(v);
	cout << biggest.first << " " << biggest.second << endl;
	biggest = process2(v);
	cout << biggest.first << " " << biggest.second << endl;
	biggest = process3(v);
	cout << biggest.first << " " << biggest.second << endl;
}
