/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 10:20:07
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 10:20:11
 * @Description: file content
 */

/*
条款38：通过复合塑模出 has-a 或 “根据某物实现出”
在设计类时，我们经常面临选择继承或组合的问题。组合（复合）通常比继承更加灵活，
减少了类间的耦合，更有利于代码的维护和扩展。
*/

class Timer {
public:
    void start() {}
    void stop() {}
};

class Stopwatch {
private:
    Timer timer; // 使用组合而非继承
public:
    void start() {
        timer.start();
    }
    void stop() {
        timer.stop();
    }
};
