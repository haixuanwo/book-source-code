
#ifndef FOO_H
#define FOO_h

#include <iostream>

typedef int T;
struct Foo{
    Foo(T t): val(t) { }
    T val;
};

std::ostream& print(std::ostream &os, const Foo &f)
{
    os << f.val;
    return os;
}

#endif
