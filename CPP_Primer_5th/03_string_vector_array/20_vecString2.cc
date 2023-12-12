
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main()
{
    vector<string> text;

    string s;
    while (getline(cin, s))
    {
        text.push_back(s);
    }
    cout << "text.size: " << text.size() << endl;

    for (auto it = text.cbegin();
        it != text.cend() && !(*it).empty(); it++)
    {
        cout << *it << endl;
    }

    for (auto it = text.cbegin();
        it != text.cend() && !it->empty(); ++it)
    {
        cout << *it << endl;
    }
}
