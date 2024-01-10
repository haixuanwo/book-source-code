
#include <algorithm>
using std::equal;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    list<const char *> roster1;

    vector<string> roster2;
    roster2 = {"hello", "so long", "tata"};
    roster1 = {"hello", "so long"};

    auto b = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    (b) ? cout << "true" : cout << false;
    cout << endl;

    return 0;
}
