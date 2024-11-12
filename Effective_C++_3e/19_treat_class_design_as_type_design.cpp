/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:23:35
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:34:22
 * @Description: file content
 */

/*
条款19：设计 class 犹如设计 type，
需要考虑对象创建、销毁、初始化、赋值、值传递、合法值、继承关系、转换、一般化等事项

设计类时，应视其为一个新的类型，考虑到所有类型设计中的要素：如何创建和销毁它，
它的初始化和赋值操作，它的值如何被传递（通过值还是引用），它的合法值是什么，
它如何与其他类型互动等。
*/

class Widget {
public:
    Widget();                       // 构造函数
    ~Widget();                      // 析构函数
    Widget(const Widget& rhs);      // 拷贝构造函数
    Widget& operator=(const Widget& rhs);  // 赋值运算符
    void swap(Widget& other) noexcept;     // 交换函数
};

void swap(Widget& a, Widget& b) noexcept {
    a.swap(b);
}
