/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:59:43
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:59:47
 * @Description: file content
 */

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#ifdef REGEX

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::smatch;
using std::regex_error;

int main()
{
	try
    {
		// r has two subexpressions:
		// the first is the part of the file name before the period
		// the second is the file extension
		regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
		smatch results;
		string filename;

		while (cin >> filename)
        {
			if (regex_search(filename, results, r))
			{
                cout << results.str(1) << endl;
				// print the first subexpression
            }
        }
    }
    catch (regex_error e)
	{
        cout << e.what() << " " << e.code() << endl;
    }

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif