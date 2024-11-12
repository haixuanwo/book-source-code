/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:03:35
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:29:49
 * @Description: file content
 */

/*
条款15：在资源管理类中提供对原始资源的访问

提供安全的访问方式到资源管理类所管理的原始资源。可以通过重载解引用运算符和箭头运算
符来实现，使得资源管理类的对象可以像原始指针一样操作其所持有的资源。
*/

class SmartPointer {
public:
    Resource& operator*() const { return *ptr; }
    Resource* operator->() const { return ptr; }
private:
    Resource* ptr;
};



