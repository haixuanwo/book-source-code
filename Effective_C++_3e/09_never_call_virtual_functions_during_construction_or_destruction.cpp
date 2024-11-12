/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:51:52
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:28:23
 * @Description: file content
 */

/*
条款9: 绝不在构造和析构过程中调用virtual函数

在构造或析构的过程中调用虚函数不会调用到派生类中覆盖的版本。
这是因为在构造和析构过程中，对象的动态类型是正在构造或析构的类。
如果调用虚函数，它会调用当前类层次结构中的那个版本，这可能不是你期望的行为。
*/

class Base {
public:
    Base() { call(); }
    virtual ~Base() { call(); }
    virtual void call() { std::cout << "Base::call()\n"; }
};

class Derived : public Base {
public:
    void call() override { std::cout << "Derived::call()\n"; }
};

// 在main中创建Derived对象
// 输出将是 "Base::call()" 而不是 "Derived::call()"
Derived d;



