/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:28:57
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:45:01
 * @Description: file content
 */

/*
条款43：学习处理模板化基类内的名称
当派生类继承自一个模板基类时，基类中的名称不会被自动地引入到派生类的作用域中。
这可能导致一些名字解析的问题，通常需要显式地引用这些名称或者使用using声明。
*/

template<typename T>
class Base {
public:
    void func() {}
};

template<typename T>
class Derived : public Base<T> {
public:
    void callFunc() {
        this->func();  // 使用this指针来指定func是从模板基类继承的
        // 或者
        Base<T>::func();  // 直接使用基类的限定名
    }
};

