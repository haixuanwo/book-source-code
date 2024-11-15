<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-15 11:33:06
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-15 11:40:39
 * @Description: file content
-->

# 31. 避免使用默认捕获模式

主要是使用显式捕获的时候，可以比较明显的让用户知道变量的声明周期：

    void addDivisorFilter()
    {
        auto divisor = computeDivisor(cal1, cal2);
        filters.emplace_back([&](int value){return value % divisor == 0;}) //危险，因为divisor在闭包里面很容易空悬，生命周期会结束
    }
如果用显式捕获的话：

    filters.emplace_back([&divisor](int value){return value % divisor == 0;}) //仍然很危险，但是起码很明显
最好的做法就是传一个this进去：

    void Widget::addFilter() const{
        auto currentObjectPtr = this;    //这样就把变量的声明周期和object绑定起来了
        filters.emplace_back([currentObjectPtr](int value){
            return value % currentObjectPtr->advisor == 0;
        })
    }


# 32. 使用初始化捕获来移动对象到闭包中

    auto func = [pw = std::make_unique<Widget>()]{    //初始化捕获（广义lambda捕获），适用于C++14及其以上
        return pw->isValidated() && pw->isArchived();
    };

    auto func = std::bind([](const std::unique_ptr<Widget>& data){}, std::make_unique<Widget>()); // C++11的版本，和上面的含义一样

# 33. 对于std::forward的auto&&形参使用decltype

在C++14中，我们可以在lambda表达式里面使用auto了，那么我们想要把传统的完美转发用lambda表达式写出来应该是什么样子的呢：

    class SomeClass{
    public:
        template<typename T>
        auto operator()(T x) const{
            return func(normalize(x));
        }
    }

    auto f=[](auto&& x){
        return func(normalize(std::forward<decltype(x)>(x)));
    };

# 34. 优先考虑lambda表达式而非std::bind**

+ lambda表达式具有更好的可读性，表达力也更强，有可能效率也更高
+ 只有在C++11中，bind还有其发挥作用的余地
