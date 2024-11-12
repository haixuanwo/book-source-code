/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:25:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:44:32
 * @Description: file content
 */

/*
条款41：了解隐式接口和编译期多态
在C++中，隐式接口不是通过继承某个基类来定义的，而是通过期望的操作来定义。
这通常通过模板实现，允许在编译时进行类型检查，实现所谓的编译期多态。
*/

template<typename T>
void printTwice(const T& value) {
    std::cout << value << " " << value << std::endl;
}

class Foo {
public:
    friend std::ostream& operator<<(std::ostream& os, const Foo& foo) {
        os << "Foo";
        return os;
    }
};

int main() {
    printTwice(42);  // 正常输出42 42
    printTwice("Hello");  // 正常输出Hello Hello
    Foo foo;
    printTwice(foo);  // 正常输出Foo Foo，因为Foo定义了<<操作符
}
