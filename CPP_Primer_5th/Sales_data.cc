/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-14 17:24:38
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-14 18:26:54
 * @Description: file content
 */

#include <iostream>
using std::istream;
using std::ostream;

#include "Sales_data.h"
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

double Sales_data::avg_price() const
{
    if (!units_sold)
    {
        return 0;
    }

    return revenue/units_sold;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

ostream& print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();

    return os;
}

istream& read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}


