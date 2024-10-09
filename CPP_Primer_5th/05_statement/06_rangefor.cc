
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main()
{
    vector<int> ivec;
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    for (auto &r : v)
    {
        r *= 2;
    }

    for (int r : v)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
