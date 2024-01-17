/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-13 23:28:14
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-13 23:28:18
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::ostream;

#include "Quote.h"

int main()
{
    Quote base("0-201-82470-1", 50);
    print_total(cout, base, 10);

    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    print_total(cout, base, 10);

    Quote *baseP = &derived;
    double undiscounted = baseP->Quote::net_price(42);
}
