
/*
条款1: 视C++为一个语言联邦
C++可以被看作是几种不同编程语言的集合：
1、C style
2、Object-Oriented C++
3、base object C++
4、Template meta C++、以及STL

每种"子语言"都有其优势和用法。

例如，C部分提供了对硬件的低级访问，面向对象部分支持封装和继承，模板部分支持泛型
编程，STL则提供了一套强大的库。理解这些部分的不同规则和最佳实践对于编写高效、可维护的
代码至关重要。
*/

// C-style
int array[10];

// Object-Oriented C++
class Widget {
public:
    void draw() const; // 类方法
};

// Template C++
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// STL
#include <vector>
std::vector<int> vec;

int main()
{

}
