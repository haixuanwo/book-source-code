/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 11:01:27
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:46:27
 * @Description: file content
 */

/*
条款52：写了placement new也要写placement delete
如果为类提供了placement new操作符，也应该提供相应的placement delete。这是因为当构造函数
抛出异常时，C++会调用placement delete来处理已分配的内存。
*/

#include <iostream>

class Widget {
public:
    Widget() { throw std::runtime_error("Failed to create Widget"); }
    void* operator new(size_t size, void* place) {
        return place;
    }
    void operator delete(void* mem, void* place) noexcept {
        // placement delete逻辑（通常为空）
    }
};

int main() {
    char buffer[sizeof(Widget)];
    try {
        Widget* w = new (buffer) Widget();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
