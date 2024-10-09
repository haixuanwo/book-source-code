
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int a = 0;
    decltype(a) c = a;
    decltype((a)) d = a; // reference to a

    ++c;
    cout << "a: " << a << " c: " << c << " d: " << d << endl;

    ++d;
    cout << "a: " << a << " c: " << c << " d: " << d << endl;


    int A = 0, B = 0;
    decltype((A)) C = A;
    decltype(A = B) D = A; // reference to A

    ++C;
    cout << "A: " << A << " C: " << C << " D: " << D << endl;

    ++D;
    cout << "A: " << A << " C: " << C << " D: " << D << endl;

    return 0;
}
