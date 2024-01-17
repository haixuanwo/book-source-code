/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 09:43:05
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 09:43:14
 * @Description: file content
 */

#ifndef BOOKEXCEPT_H
#define BOOKEXCEPT_H

#include <stdexcept>
#include <string>

// hypothetical exception classes for a bookstore application
class out_of_stock: public std::runtime_error
{
public:
    explicit out_of_stock(const std::string &s)
        : std::runtime_error(s)
    {

    }
};

class isbn_mismatch: public std::logic_error
{
public:
    explicit isbn_mismatch(const std::string &s)
        : std::logic_error(s)
    {

    }

    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs)
        : std::logic_error(s), left(lhs), right(rhs)
    {

    }

    const std::string left, right;
};

#endif
