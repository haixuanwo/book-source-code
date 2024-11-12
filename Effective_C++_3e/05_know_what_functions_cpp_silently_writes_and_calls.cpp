

/*
条款5:了解C++默默编写并调用哪些函数

C++编译器会自动为类生成默认：
1、构造函数
2、析构函数
3、拷贝构造函数
4、拷贝赋值运算符

如果未明确声明这些。理解这一行为对于设计类及其行为至关重要，尤其是涉及资源管
理（如动态内存分配）时。
*/

class Widget {
public:
    Widget() {}     // 默认构造函数

    ~Widget() {}    // 默认析构函数

    Widget(const Widget& rhs) : id(rhs.id) {} // 拷贝构造函数

    Widget& operator=(const Widget& rhs) {    // 拷贝赋值运算符
        id = rhs.id;
        return *this;
    }

private:
    int id;
};
