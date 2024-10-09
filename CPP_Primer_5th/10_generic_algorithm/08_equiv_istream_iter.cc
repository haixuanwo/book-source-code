
#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);

    for (auto &it : vec)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
