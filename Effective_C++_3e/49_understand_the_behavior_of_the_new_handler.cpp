/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:55:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:55:13
 * @Description: file content
 */

/*
条款49：了解new-handler的行为
C++允许设置一个new-handler函数，这是一个由std::set_new_handler()设置的函数，
当operator new无法分配足够内存时会被调用。
*/

#include <iostream>
#include <new>
#include <cstdlib>

void myNewHandler() {
    std::cerr << "Custom new handler: Memory allocation failed, terminating\n";
    std::abort();
}

int main() {
    std::set_new_handler(myNewHandler);
    try {
        while (true) {
            new int[100000000ul];  // 试图分配大量内存
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Caught bad_alloc: " << e.what() << '\n';
    }
    return 0;
}

