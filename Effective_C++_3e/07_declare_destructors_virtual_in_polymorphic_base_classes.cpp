/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:48:00
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:27:07
 * @Description: file content
 */

/*
条款7: 为多态基类声明virtual析构函数

当一个类用作基类，并且通过基类的指针或引用来管理派生类对象时，应当声明一个
虚析构函数。这确保了在通过基类指针删除一个派生类对象时，可以正确地调用派生
类的析构函数，避免资源泄露。
*/

class Base {
public:
    virtual ~Base() {
        // 基类的析构函数
    }
};

class Derived : public Base {
public:
    ~Derived() {
        // 派生类的资源清理
    }
};

Base* b = new Derived();
delete b;  // 正确调用Derived的析构函数，然后是Base的析构函数
