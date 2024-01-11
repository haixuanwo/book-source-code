/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-11 19:20:52
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-11 19:21:04
 * @Description: file content
 *
 */


#include "../make_plural.h"

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::ostream;

#include <algorithm>
using std::for_each;
using std::find_if;
using std::stable_sort;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstddef>
using std::size_t;

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

// determine whether a length of a given word is 6 or more
bool GT(const string &s, string::size_type m)
{
    return s.size() >= m;
}

class SizeComp {
public:
	SizeComp() = delete;  // no default constructor
	SizeComp &operator=(const SizeComp&) = delete; // no assignment
	~SizeComp() = default;

	// constructor with a parameter for each captured variable
	SizeComp(size_t n): sz(n) { }

	// call operator with the same return type,
	// parameters, and body as the lambda
	bool operator()(const string &s) const { return s.size() >= sz; }
private:
	size_t sz;  // a data member for each variable captured by value
};

class PrintString {
public:
	PrintString() = delete;   // no default constructor
	PrintString(ostream &o) : os(o) { }
	void operator()(const string &s) const { os << s << " "; }
private:
	ostream &os;
};

class ShorterString {
public:
	bool operator()(const string &s1, const string &s2) const
	{ return s1.size() < s2.size(); }
};

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());

	// print the sorted contents
	for_each(words.begin(), words.end(), PrintString(cerr));
	cerr << endl;

    // unique reorders the input so that each word appears once in the
    // front part of the range
	// returns an iterator one past the unique range;
    auto end_unique = unique(words.begin(), words.end());

    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());

	// print the reduced vector
	for_each(words.begin(), words.end(), PrintString(cerr));
	cerr << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  // puts words in alphabetic order and removes duplicates

    // sort words by size using object of type ShorterString
	// maintaining alphabetic order for words of the same size
    stable_sort(words.begin(), words.end(), ShorterString());

	// use object of type SizeComp to find
	// the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));

	// compute the number of elements with size >= sz
	auto count = words.end() - wc;

	// print results
    cout << count << " " << make_plural(count, "word", "s")
         << " " << sz << " characters or longer" << endl;

	// use object of type PrintString
	// to print the contents of words, each one followed by a space
	for_each(wc, words.end(), PrintString(cout));
	cout << endl;
}

int main()
{
    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        // insert next book's contents at end of words
        words.push_back(next_word);
    }

	biggies(words, 6);

	return 0;
}
