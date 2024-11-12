/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:59:59
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:29:08
 * @Description: file content
 */

/*
条款13：以对象管理资源

使用对象来管理资源（如动态内存、文件句柄、网络连接等），利用C++的构造函数和析构
函数，可以自动化资源的获取和释放，避免资源泄漏。这通常通过实现一个
RAII（Resource Acquisition Is Initialization）类来完成。
*/

class FileHandler {
public:
    FileHandler(const char* filename) {
        file = fopen(filename, "w");
    }
    ~FileHandler() {
        if (file) fclose(file);
    }
private:
    FILE* file;
};
