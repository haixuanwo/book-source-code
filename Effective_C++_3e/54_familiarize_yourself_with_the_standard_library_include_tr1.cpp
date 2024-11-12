/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 11:05:55
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:46:43
 * @Description: file content
 */

/*
条款54：让自己熟悉包括TR1在内的标准程序库
熟悉标准库（包括TR1的扩展和C++11及之后标准的更新）可以显著提高开发效率和代码质量。

使用标准库中的智能指针（如std::shared_ptr）管理资源：
*/

#include <memory>

void process(std::shared_ptr<int> ptr) {
    std::cout << "Processing: " << *ptr << std::endl;
}

int main() {
    std::shared_ptr<int> p = std::make_shared<int>(42);
    process(p);
}
