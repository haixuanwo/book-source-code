/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 18:08:40
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 19:26:26
 * @Description: file content
 */

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#ifdef REGEX

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;

int main()
{
	string zip = "\\d{5}-\\d{4}|\\d{5}";

	string test_str = "908.647.4306 164 gates, 07933 07933-1257";
	regex r(zip);  // a regex to find the parts in our pattern
	smatch results;

	if (regex_search(test_str, results, r))
		cout << results.str() << endl;

	sregex_iterator it(test_str.begin(), test_str.end(), r);
	sregex_iterator end_it;         // end iterator
	while (it != end_it) {
		cout << it->str() << endl;  // print current match
		++it;                       // advance iterator for next search
	}

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif
