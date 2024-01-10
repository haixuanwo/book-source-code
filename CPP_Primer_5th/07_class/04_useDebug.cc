/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 18:51:54
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 18:55:06
 * @Description: file content
 */

#include <iostream>
using std::cerr;
using std::endl;

#include "Debug.h"

int main()
{
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any())
    {
        cerr << "print appropriate error messages" << endl;
    }

    constexpr Debug prod(false);
    if (prod.any())
    {
        cerr << "print an error messages" << endl;
    }

    IO_Subsystem ioErrs;
    if (ioErrs.default_debug())
    {
        cerr << "printf message 3" << endl;
    }

    ioErrs.set_debug(true);
    if (ioErrs.default_debug())
    {
        cerr << "printf message 4" << endl;
    }
    ioErrs.set_debug(false);

    HW_Subsystem hw;
    hw.set_debug(true);
    if (ioErrs.default_debug() || hw.default_debug())
    {
        cerr << "printf message 5" << endl;
    }
}
