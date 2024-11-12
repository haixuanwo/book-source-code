/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:21:38
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:22:47
 * @Description: file content
 */

/*
条款39：明智而审慎地使用private继承
私有继承应被视为一种实现细节，它不应被用作表达"is-a"关系。私有继承意味着“根据某物实现出”，
而不是“是一种”。
*/

class Engine {
public:
    void start() {}
    void stop() {}
};

class Car : private Engine { // 私有继承表示Car是通过Engine实现的
public:
    void startEngine() {
        Engine::start(); // 调用Engine的功能
    }
};
