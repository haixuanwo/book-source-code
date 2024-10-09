/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:37:38
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:37:41
 * @Description: file content
 */

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#define REGEX
#ifdef REGEX

#include <iostream>
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
		// missing close bracket after alnum; the constructor will throw
		regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
	}
    catch (regex_error e)
	{
        cout << e.what() << "\ncode: " << e.code() << endl;
    }

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif
