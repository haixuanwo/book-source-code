/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:15:34
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:17:17
 * @Description: file content
 */

/*
条款37：绝不重新定义继承而来的缺省参数值
在C++中，虚拟函数的默认参数是静态绑定的，而不是动态绑定的。这意味着被调用的
默认参数值取决于指针或引用的静态类型，而不是对象的实际类型。
*/

class Base {
public:
    virtual void foo(int x = 10) {
        std::cout << "Base foo with x = " << x << std::endl;
    }
};

class Derived : public Base {
public:
    void foo(int x = 20) override {
        std::cout << "Derived foo with x = " << x << std::endl;
    }
};

Base* b = new Derived();
b->foo(); // 输出: "Derived foo with x = 10"
delete b;

