
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    cout << "The value of ival\n"
        << "direct value: " << ival << "\n"
        << "indirect value: " << *pi << "\n"
        << "doubly indirect value: " << **ppi
        << endl;

    int i = 2;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    cout << "i = " << i << endl;

    *p1 *= *p1;
    cout << "i = " << i << endl;

    return 0;
}
