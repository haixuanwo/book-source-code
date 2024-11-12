/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:31:26
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:32:33
 * @Description: file content
 */

/*
条款44：将与参数无关的代码抽离templates
当模板中的代码与模板参数无关时，应当将这部分代码抽离出来，以避免不必要的代码膨胀。
通常，可以将这部分代码放入非模板的基类或者非模板的成员函数中。
*/

class NonTemplateBase {
protected:
    void commonFunction() const {
        std::cout << "Performing a common action" << std::endl;
    }
};

template<typename T>
class MyTemplateClass : public NonTemplateBase {
public:
    void doSomething() {
        commonFunction();  // 调用非模板基类的函数
    }
};
