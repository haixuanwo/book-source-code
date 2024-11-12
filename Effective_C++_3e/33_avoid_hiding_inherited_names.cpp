/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:58:12
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:40:10
 * @Description: file content
 */

/*
条款33：避免遮掩继承而来的名称
在派生类中，基类的方法可能会被派生类的方法遮掩，即使它们的参数不同。
使用using声明可以使基类中的方法在派生类中可见。
*/

class Base {
public:
    void doSomething(int) {}
};

class Derived : public Base {
public:
    using Base::doSomething; // 使所有的 doSomething 版本在 Derived 中可见
    void doSomething(double) {}
};

// 使用
Derived d;
d.doSomething(10);    // 调用 Base::doSomething(int)
d.doSomething(3.14);  // 调用 Derived::doSomething(double)

