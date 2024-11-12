/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:50:35
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:51:39
 * @Description: file content
 */

/*
条款47：请使用 traits classes 表示类型信息
特性类（traits classes）是模板元编程中用来存储类型信息的结构，它们通过模板和特化来定义和
使用类型相关的数据。
*/

#include <iostream>
#include <type_traits>

template<typename T>
void foo(const T& x) {
    if (std::is_integral<T>::value) {
        std::cout << x << " is an integral type." << std::endl;
    } else {
        std::cout << x << " is not an integral type." << std::endl;
    }
}

int main() {
    foo(10);    // 输出：10 is an integral type.
    foo(3.14);  // 输出：3.14 is not an integral type.
}

