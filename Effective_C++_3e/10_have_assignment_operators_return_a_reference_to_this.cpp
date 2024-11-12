/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:55:17
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:28:41
 * @Description: file content
 */

/*
条款10: 令operator=返回一个reference to *this

为了实现连续赋值，赋值运算符应该返回一个指向当前对象的引用。这允许链式赋值，
并且是对赋值操作符的一个常见和期望的实现。
*/

class Widget {
public:
    Widget& operator=(const Widget& rhs) {
        // 检查自赋值
        if (this == &rhs) return *this;

        // 复制数据
        data = rhs.data;
        return *this; // 使赋值可以链式进行
    }
private:
    int data;
};

Widget a, b, c;
a = b = c;  // 链式赋值


