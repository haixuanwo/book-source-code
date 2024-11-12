/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:04:57
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:43:23
 * @Description: file content
 */

/*
条款35：考虑virtual函数以外的其他选择
虚函数提供了一种实现多态的方式，但它们不是唯一的选择。模板和函数指针也可以用来实现在运行时或
编译时的策略选择。
*/

template <typename DrawingPolicy>
class Shape
{
public:
    void draw()
    {
        DrawingPolicy policy;
        policy.draw();  // 编译时多态
    }
};

class CirclePolicy
{
public:
    void draw()
    {
        // 绘制圆形的代码
    }
};

// 使用
Shape<CirclePolicy> circle;
circle.draw();
