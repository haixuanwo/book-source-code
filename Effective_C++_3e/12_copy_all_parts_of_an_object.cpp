/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:58:43
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:29:01
 * @Description: file content
 */

/*
条款12：复制对象时勿忘其每一个成分

在实现拷贝构造函数和赋值运算符时，确保复制对象的所有成员变量和基类部分。
忽略任何成员或基类的复制都可能导致运行时错误或对象状态不一致。
*/

class Base {
public:
    int b;
};

class Derived : public Base {
public:
    Derived& operator=(const Derived& rhs) {
        Base::operator=(rhs);  // 复制基类部分
        d = rhs.d;             // 复制派生类部分
        return *this;
    }
private:
    int d;
};
