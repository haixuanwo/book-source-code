/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:07:34
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:30:14
 * @Description: file content
 */

/*
条款17：以独立语句将newed对象置入智能指针

为了防止内存泄漏，应该在单独的语句中创建动态对象并立即用智能指针管理它。
如果在创建智能指针的表达式中直接使用new，并且该表达式是一个复杂表达式，
就有可能在new之后、智能指针取得控制权之前发生异常，从而导致内存泄漏。
*/

#include <memory>

void process(std::shared_ptr<int> ptr)
{
    // 使用 ptr
}

int main() {
    std::shared_ptr<int> ptr(new int(42));  // 推荐分开书写
    process(ptr);  // 安全传递给函数
}
