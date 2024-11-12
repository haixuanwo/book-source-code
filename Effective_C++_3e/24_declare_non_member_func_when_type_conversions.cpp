

/*
条款24：若所有参数皆需类型转换，请为此采用 non-member 函数

若所有参数皆需类型转换，请为此采用 non-member 函数
当一个操作符或函数需要对所有参数进行类型转换时，最好将其实现为非成员函数。
这样，所有参数都将平等地进行隐式类型转换，提高接口的灵活性和通用性。
*/

class Widget {
public:
    Widget(int n) {}  // 允许从 int 构造
};

Widget operator+(const Widget& lhs, const Widget& rhs) {
    // 实现两个 Widget 相加
    return Widget(0);  // 临时示例返回
}

int main() {
    Widget w1(10), w2(20);
    Widget w3 = w1 + w2;  // 正常
    Widget w4 = w1 + 30;  // 自动将 30 转换为 Widget
    Widget w5 = 40 + w2;  // 自动将 40 转换为 Widget
}

