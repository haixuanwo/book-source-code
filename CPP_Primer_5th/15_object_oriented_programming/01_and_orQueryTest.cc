/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-12 22:26:42
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-12 22:39:07
 * @Description: file content
 */

#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>

using std::set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    TextQuery file = get_file(argc, argv);

    while (true)
    {
        string sought1, sought2, sought3;

        if (!get_words(sought1, sought2))
        {
            break;
        }

        cout << "\n enter third word: ";
        cin >> sought3;

        Query q = Query(sought1) & Query(sought2) | Query(sought3);
        cout << "\n Executing Query for: " << q << endl;
        const auto results = q.eval(file);
        print(cout, results);
    }

    return 0;
}
