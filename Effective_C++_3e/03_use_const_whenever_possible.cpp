

/*
条款3: 尽可能使用const
使用const可以提高代码的可读性，减少编程错误，因为它指定了变量不可修改。
应用const到各种适当的场合，包括函数参数、返回类型、成员函数本身，确保
程序的正确性和清晰性。
*/

void f(const Widget& w) {
    // w.doSomething(); // 这样是错误的，如果doSomething()不是const成员函数
    w.show() const; // 正确
}

class Widget
{
public:
    std::size_t size() const { return data.size(); }

private:
    std::vector<int> data;
};
