/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:57:15
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:28:53
 * @Description: file content
 */

/*
条款11：在 operator= 中处理“自我赋值”

当设计赋值运算符时，必须考虑到对象可能会将自身赋值给自身的情况。如果不妥善处理，
这种自我赋值可能会导致程序错误，比如意外的资源释放。这可以通过检查赋值运算符的
参数是否与当前对象相同来防止。
*/

class Widget {
public:
    Widget& operator=(const Widget& rhs) {
        if (this == &rhs) return *this; // 自我赋值检查
        // 释放旧资源
        delete[] data;
        // 复制赋值的数据
        data = new int[rhs.size];
        std::copy(rhs.data, rhs.data + rhs.size, data);
        size = rhs.size;
        return *this;
    }
private:
    int* data;
    std::size_t size;
};
