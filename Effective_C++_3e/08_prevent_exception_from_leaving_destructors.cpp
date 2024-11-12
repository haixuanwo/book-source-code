/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:50:12
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:27:52
 * @Description: file content
 */

/*
条款8: 别让异常逃离析构函数

还有构造

在析构函数中抛出异常是非常危险的，因为如果在析构过程中已经因为另一个异常而处于
堆栈展开过程中，抛出另一个异常将导致程序终止。因此，析构函数应该捕获并处理所有
异常，或者避免调用可能抛出异常的函数。
*/

class ResourceManager {
public:
    ~ResourceManager() {
        try {
            // 尝试释放资源，可能抛出异常
            releaseResource();
        } catch(...) {
            // 处理异常，确保不逃离析构函数
            handleError();
        }
    }
private:
    void releaseResource();
    void handleError();
};
