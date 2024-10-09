/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-13 10:04:23
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-13 15:34:21
 * @Description: file content
 */

#include "Query.h"
#include "TextQuery.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <set>
using std::set;

int main(int argc, char **argv)
{
    TextQuery file = get_file(argc, argv);

    do
    {
        string sought1, sought2;
        if (!get_words(sought1, sought2))
        {
            break;
        }

        Query andq = Query(sought1) & Query(sought2);
        cout << "\n Executing query for: " << andq << endl;
        auto results = andq.eval(file);
        print(cout, results);

        results = Query(sought1).eval(file);
        cout << "\n Executing query: " << Query(sought1) << endl;
        print(cout, results);

        results = Query(sought2).eval(file);
        cout << "\n Executing query: " << Query(sought2) << endl;
        print(cout, results);

    } while (true);

    return 0;
}
