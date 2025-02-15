/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 18:05:51
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 18:07:07
 * @Description: file content
 */

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#ifdef REGEX

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::smatch;
using std::regex_error;

// the area code doesn't have a separator;
// the remaining separators must be equal
// OR the area code parens are correct and
// the next separator is blank or missing
bool valid(const smatch& m)
{
	// if there is an open parenthesis before the area code
	if(m[1].matched)
    {
		// the area code must be followed by a close parenthesis
		// and followed immediately by the rest of the number or a space
	    return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    }
    else
    {
		// then there can't be a close after the area code
		// the delimiters between the other two components must match
		return !m[3].matched && m[4].str() == m[6].str();
    }
}

int main()
{
	// phone has 10 digits, optional parentheses around the area code
	// components are separated by an optional space, ',' or '-'
	string phone = "\\(?\\d{3}\\)?[-. ]?\\d{3}[-. ]?\\d{4}";

	// our overall expression has seven subexpressions:
	//    ( ddd ) separator ddd separator dddd
	// subexpressions 1, 3, 4, and 6 are optional;
	// subexpressions 2, 5, and 7 hold the number
	phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);  // a regex to find our pattern
	smatch m;        // a match object to hold the results
	string s;        // a string to search

	// read each record from the input file
	while (getline(cin, s))
    {
		// for each matching phone number
		for (sregex_iterator it(s.begin(), s.end(), r), end_it;
			       it != end_it; ++it)
        {
			// check whether the number's formatting is valid
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;
        }
    }

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif
