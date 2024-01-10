
#include <algorithm>
using std::copy;
using std::sort;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec;
    istream_iterator<int> in(cin), eof;
    copy(in, eof, back_inserter(vec));

    sort(vec.begin(), vec.end());
    vector<int> vec2(vec);

    sort(vec.rbegin(), vec.rend());
    ostream_iterator<int> out(cout, " ");
    copy(vec.begin(), vec.end(), out);
    cout << endl;

    copy(vec2.begin(), vec2.end(), out);
    cout << endl;

    auto it = vec.begin();
    vector<int>::reverse_iterator rev_it(it);
    cout << *(rev_it.base()) << endl;
    cout << *it << endl;
    cout << *(rev_it.base()) << endl;
    cout << *(rev_it - 1) << endl;

    return 0;
}
