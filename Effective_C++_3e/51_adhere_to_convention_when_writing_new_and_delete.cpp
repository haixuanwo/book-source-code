

/*
条款51：编写new和delete时需固守常规
自定义new和delete应谨慎进行，确保它们遵循C++标准的行为。这包括处理零字节分配、
对齐需求和异常。
*/

#include <iostream>
#include <new>

void* operator new(size_t size) {
    if (size == 0) {
        size = 1;  // 零字节请求处理
    }
    while (true) {
        if (void* mem = std::malloc(size)) {
            return mem;
        } else {
            std::new_handler handler = std::get_new_handler();
            if (handler) {
                handler();
            } else {
                throw std::bad_alloc();  // 确保抛出异常
            }
        }
    }
}

void operator delete(void* mem) noexcept {
    std::free(mem);
}

int main() {
    int* p = new int;
    delete p;
}
