
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int grade = 75;
    cout << ((grade < 60) ? "fail" : "pass");
    cout << endl;

    cout << (grade < 60) ? "fail" : "pass";
    cout << endl;

    cout << (grade < 60);
    cout ? "fail" : "pass";

    cout << endl;
    int i = 15, j = 20;
    cout << (i < j ? i : j);
    cout << endl;

    cout << (i < j) ? i : j;
    cout << endl;

    cout << (i < j);
    cout ? i : j;
    cout << endl;

    return 0;
}
