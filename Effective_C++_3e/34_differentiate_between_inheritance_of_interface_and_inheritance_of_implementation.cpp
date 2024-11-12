/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:01:51
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:43:08
 * @Description: file content
 */

/*
条款34：区分接口继承和实现继承
这条建议强调继承的两个方面：接口继承（通过纯虚函数定义一个接口，子类必须实现该接口）和实现
继承（基类提供方法的默认实现）。清晰地区分这两者可以提高代码的清晰度和可重用性。
*/

class IShape {
public:
    virtual void draw() const = 0; // 纯接口
    virtual ~IShape() {}
};

class Circle : public IShape {
public:
    void draw() const override {
        // 绘制圆形的代码
    }
};



