/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 18:48:12
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 18:48:31
 * @Description: file content
 */

#include <iostream>

void foo(int a,int b)
{
    std::cout<< a << "," << b <<std::endl;
}

int get_num()
{
    static int i=0;
    return ++i;
}

int main()
{
    foo(get_num(),get_num());
}
