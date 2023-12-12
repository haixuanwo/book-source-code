
#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec;
    int cnt = 10;

    while (cnt > 0)
    {
        ivec.push_back(cnt--);
    }

    auto iter = ivec.begin();
    while (iter != ivec.end())
    {
        cout << *iter++ << endl;
    }

    vector<int> vec2(10, 0);
    cnt = vec2.size();
    for (vector<int>::size_type ix = 0; ix != vec2.size(); ix++, -cnt)
    {
        vec2[ix] = cnt;
    }

    iter = vec2.begin();
    while (iter != vec2.end())
    {
        cout << *iter++ << endl;
    }

    return 0;
}
