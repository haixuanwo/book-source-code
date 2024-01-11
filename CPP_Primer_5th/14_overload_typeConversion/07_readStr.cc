


#include <algorithm>
using std::for_each;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class PrintString
{
public:
    PrintString(ostream &o = cout, char c = ' '): os(o),  sep(c) { }
    void operator()(const string &s) const { os << s << sep; }

private:
    ostream &os;
    char sep;
};

class ReadLine
{
public:
    ReadLine() = delete;
    ReadLine(istream &i) : is(i) { }
    bool operator()(string &s) const { getline(is, s); return true; }

private:
    istream &is;
};

int main()
{
    vector<string> vs;
    ReadLine rl(cin);

    string s;
    rl(s);
    vs.push_back(s);

    cout << "read: " << vs.size() << " elements" << endl;
    PrintString printer;
    printer(s);

    PrintString errors(cerr, '\n');
    errors(s);

    cerr << "for_each printing to cerr" << endl;
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
}
