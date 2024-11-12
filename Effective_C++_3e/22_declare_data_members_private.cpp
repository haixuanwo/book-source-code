/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:29:52
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:35:55
 * @Description: file content
 */

/*
条款22：将成员变量声明为 private

对于类中的数据成员，应始终将其声明为 private。这有助于封装，确保数据成员不会
被类外的代码直接访问和修改，迫使外部代码通过类提供的公共接口来互动，从而更好地
控制数据。
*/

class Widget {
public:
    void setData(int d) { data = d; }
    int getData() const { return data; }
private:
    int data;
};
