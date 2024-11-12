/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:52:52
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:52:57
 * @Description: file content
 */

/*
条款48：认识 template 元编程的两个世界
模板元编程允许程序员在编译时进行计算，从而提供了生成更优化和自定义代码的能力。
这通常涉及到递归模板实例化和使用模板特化来控制递归。
*/

template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    std::cout << "Factorial of 5 is " << Factorial<5>::value << std::endl;  // 输出：Factorial of 5 is 120
}
