/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 23:16:54
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 09:26:22
 * @Description: file content
 */


#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#define REGEX
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

int main()
{
	try
    {
		// one or more alphanumeric characters followed by a '.'
		// followed by "cpp" or "cxx" or "cc"
		regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);

		smatch results; // object to hold details about the match
		string filename;

		while (cin >> filename)
        {
			if (regex_search(filename, results, r))
            {
				cout << results.str() << endl;  // print the match
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