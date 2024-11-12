/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:32:05
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:37:27
 * @Description: file content
 */

/*
条款28：避免返回 handles 指向对象内部成分
返回到对象内部的引用、指针或迭代器，可能会导致外部代码能够修改私有数据，
或在对象生命周期结束后仍持有这些句柄，从而导致悬挂引用。应尽量避免这种设计，除非确实需要。
*/

class Widget {
public:
    // 不安全的获取内部数据的方式
    int& getData() { return data; }

    // 更安全的做法
    int getData() const { return data; }  // 返回数据的副本
private:
    int data;
};
