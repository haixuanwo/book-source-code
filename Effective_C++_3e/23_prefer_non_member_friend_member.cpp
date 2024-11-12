/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:31:14
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:36:04
 * @Description: file content
 */

/*
条款23：宁以 non-member、non-friend 替换 member 函数

宁以 non-member、non-friend 替换 member 函数
当函数可以实现为非成员非友元函数时，应该这么做。这样做可以增加封装性、包裹性和
可重用性，因为这些函数只能访问公有接口，而不是类内部的私有或受保护成分。
*/

class Widget {
public:
    void doSomething() { /* 实现 */ }
};

// 非成员函数
void processWidget(const Widget& w) {
    w.doSomething();
}

