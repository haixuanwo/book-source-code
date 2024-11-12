/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:45:59
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:26:33
 * @Description: file content
 */

/*
条款6: 若不想使用编译器自动生成的函数，就该明确拒绝

在C++中，如果你不提供拷贝构造函数和拷贝赋值运算符，编译器会为你自动生成。
但有时候，你并不希望你的对象被拷贝，例如，当你的类包含了对资源如文件句柄
或网络连接的独占控制时。在这种情况下，你应该阻止生成这些函数，可以通过将
它们声明为private并且不提供实现来实现：

C++11可用delete
*/

class Uncopyable {
protected:  // 允许派生类构造和析构
    Uncopyable() {}
    ~Uncopyable() {}
private:    // 阻止拷贝构造函数和赋值运算符
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class MyResource: private Uncopyable {
    // 现在MyResource类不能被拷贝
};
