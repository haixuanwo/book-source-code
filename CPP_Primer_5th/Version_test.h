
#ifndef VERSION_TEST_H
#define VERSION_TEST_H

#if __cplusplus == 201103L
#endif

#ifndef STRING_NUMERIC_CONVS
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <cstdio>

inline std::string to_string(int i)
{
    char buf[100];
    std::sprintf(buf, "%d", i);
    return buf;
}

inline double stod(const std::string &s, std::size_t * = 0)
{
    char **buf = 0;
    return std::strtod(s.c_str(), buf);
}
#endif

#include <iostream>

#ifndef HEX_MANIPS
inline std::ostream &defaultfloat(std::ostream &os)
{
    os.unsetf(std::ios_base::floatfield);
    return os;
}
#endif

#endif
