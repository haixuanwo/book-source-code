/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 10:00:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 10:00:13
 * @Description: file content
 */

#include <iostream>
#include <string>

int main()
{
    std::string s;

    // ok: calls std::getline(std::istream&, const std::string&)
    getline(std::cin, s);

	std::cout << s << std::endl;

    return 0;
}

