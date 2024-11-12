/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:08:57
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:43:38
 * @Description: file content
 */

/*
条款36：绝不重新定义继承而来的缺省参数值
在C++中，虚拟函数的默认参数是静态绑定的，而不是动态绑定的。这意味着被调用的
默认参数值取决于指针或引用的静态类型，而不是对象的实际类型。
*/

#include <iostream>

class Base {
public:
    void doSomething() {
        std::cout << "Base doing something" << std::endl;
    }
};

class Derived : public Base {
public:
    void doSomething() {
        std::cout << "Derived doing something different" << std::endl;
    }
};

Base* b = new Derived();
b->doSomething(); // 输出: "Base doing something", 因为函数不是虚拟的
delete b;
