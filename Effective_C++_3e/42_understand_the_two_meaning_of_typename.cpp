/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:27:10
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:44:46
 * @Description: file content
 */

/*
条款42：了解typename的双重含义
typename在模板编程中用于两种情况：
一是用来声明一个类型，
二是在模板定义内部，用来指明一个依赖于模板参数的名字是一个类型。
*/

template<typename T>
class MyClass {
    typename T::SubType* ptr;  // 使用typename来指定SubType是一个类型
public:
    MyClass() : ptr(nullptr) {}
};
