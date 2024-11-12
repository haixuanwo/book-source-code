/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:57:25
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:58:38
 * @Description: file content
 */

/*
条款50：明白new和delete的合理替换时机
在某些情况下，替换默认的内存分配和释放机制可以提供额外的性能优势或特殊的功能，
例如追踪内存使用或限制内存使用。
*/

void* operator new(size_t size) {
    if (void* mem = malloc(size)) {
        std::cout << "Custom new operator allocating " << size << " bytes\n";
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void* mem) noexcept {
    std::cout << "Custom delete operator freeing memory\n";
    free(mem);
}

int main() {
    int* p = new int;
    delete p;
    return 0;
}
