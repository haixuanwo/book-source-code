/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:28:03
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:35:41
 * @Description: file content
 */

/*
条款21：必须返回对象时，别妄想返回其 reference

必须返回对象时，别妄想返回其 reference当函数需要返回一个新创建的对象时，
尽管可能会担心性能问题，但返回对象的引用是不可行的，因为它可能指向一个已经
离开作用域的局部对象。正确的做法是返回对象本身，依赖编译器优化如返回值优化
（Return Value Optimization, RVO）来减少性能损失。
*/

class Widget {
public:
    Widget() { /* 初始化 */ }
};

Widget createWidget() {
    Widget w;
    // 对 w 进行各种操作
    return w;  // 返回一个 Widget 实例
}

int main() {
    Widget myWidget = createWidget();  // 使用 RVO, 不会发生额外的复制
}

