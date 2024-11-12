/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:39:43
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 09:41:55
 * @Description: file content
 */

/*
条款29：为“异常安全”而努力是值得的

确保代码在面对异常时依旧能正确释放资源、不泄露内存，并保持数据的一致性。
这通常涉及到三种异常安全保证：
1、基本保证
2、强保证
3、不抛异常保证
在设计函数时，应考虑哪种保证最适合其操作。
*/

#include <vector>

class Widget
{
public:
    void addElement(int element)
    {
        data.push_back(element);  // vector的push_back提供强异常安全保证
    }

private:
    std::vector<int> data;
};

