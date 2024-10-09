
#include <string>
using std::string;

#include <cctype>
using std::isupper;
using std::toupper;
using std::islower;
using std::tolower;
using std::isalpha;
using std::isspace;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string s("Hello World!!!!");
    decltype(s.size()) punct_cnt = 0;

    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;

    cout << punct_cnt
        << " punctuation characters in " << s << endl;

    string orig = s;
    for (auto &c : s)
    {
        c = toupper(c);
    }
    cout << s << endl;

    s = orig;
    decltype(s.size()) index = 0;

    while (index != s.size() && !isspace(s[index]))
    {
        s[index] = toupper(s[index]);
        ++index;
    }
    cout << s << endl;

    return 0;
}
