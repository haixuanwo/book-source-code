/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:20:36
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:36:25
 * @Description: file content
 */

/*
条款25：考虑写出一个不抛异常的 swap 函数

考虑写出一个不抛异常的swap函数
为自定义类型提供一个特化的swap函数可以极大地提高算法的效率，尤其是在类型内部
含有指针等资源时。此外，定义为 noexcept 的 swap 函数还可以保证在特定上下文中
不会抛出异常，使得类型在容器如 std::vector 中表现更好。
*/

#include <utility>  // 包含 std::swap

class Widget {
public:
    Widget() { /* 初始化 */ }
    friend void swap(Widget& a, Widget& b) noexcept {
        using std::swap;
        swap(a.data, b.data);  // 交换资源
    }
private:
    int* data;
};

int main() {
    Widget w1, w2;
    swap(w1, w2);  // 使用特化的 swap 函数
}
