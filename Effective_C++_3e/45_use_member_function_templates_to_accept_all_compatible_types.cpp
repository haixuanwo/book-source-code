/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:33:57
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:45:23
 * @Description: file content
 */

/*
条款45：运用成员函数模板接受所有兼容类型
成员函数模板可以让类的某些功能接受除了类类型之外的其他类型，
只要这些类型可以转换到类类型或与之兼容。
*/

class MyClass {
public:
    MyClass(int x) : value(x) {}

    template<typename T>
    MyClass(const T& other) {
        value = other.value;  // 假设T类型有一个名为value的成员
    }

    int value;
};

MyClass obj1(10);
MyClass obj2 = obj1;  // 调用拷贝构造函数
MyClass obj3 = MyClass(20);  // 调用模板构造函数

