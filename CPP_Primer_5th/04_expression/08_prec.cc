
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << 6 + 3*4/2 + 2 << endl;
    cout << ((6 + ((3*4)/2)) + 2) << endl;

    int temp = 3*4;
    int temp2 = temp/2;
    int temp3 = temp2 + 6;
    int result = temp3 + 2;
    cout << result << endl;

    cout << (6 + 3)*(4/2 + 2) << endl;
    cout << ((6 + 3)*4)/2 + 2 << endl;
    cout << 6 + 3*4/(2 + 2) << endl;

    return 0;
}
