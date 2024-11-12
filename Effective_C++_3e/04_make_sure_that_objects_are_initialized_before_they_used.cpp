/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:40:37
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:24:36
 * @Description: file content
 */

/*
条款4: 确保对象使用前已先被初始化

1、内置对象手工初始化
2、构造函数成员初值列表，与声明次序相同
3、使用local static对象

在C++中，未初始化的变量可能导致随机运行时错误。最好的做法是在构造对象时
立即给它赋值。在构造函数初始化列表中初始化字段比在构造函数体内赋值更为高效。
*/

// 1、在构造函数初始化列表中初始化字段
class Widget {
public:
    Widget(int i, bool b) : id(i), valid(b) {} // 初始化列表
private:
    int id;
    bool valid;
};

// 2、静态局部对象
Widget &getItem()
{
    static Widget item(0, false);
}
