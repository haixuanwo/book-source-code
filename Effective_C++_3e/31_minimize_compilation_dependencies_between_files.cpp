/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:47:36
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 09:47:41
 * @Description: file content
 */

/*
条款31：将文件间的编译依存关系降至最低
这条建议的核心是减少代码之间的耦合，特别是在编译时。这样做可以减少编译时间，
也让代码更易于管理。使用前向声明（Forward declaration）是一个减少头文件依赖的有效方法。

假设有两个类A和B，其中A只需要知道B的存在而不需要知道具体实现：
*/

// B.h
class B {
public:
    void doSomething();
};

// A.h
class B; // 前向声明
class A {
public:
    B* b;
    void useB();
};

// A.cpp
#include "B.h"
void A::useB() {
    b->doSomething();
}

