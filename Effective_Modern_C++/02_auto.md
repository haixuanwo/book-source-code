<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-15 10:04:29
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-15 10:09:50
 * @Description: file content
-->

# 5. 优先考虑auto而非显式类型声明

没有初始化auto的时候，会从编译器阶段就报错;
可以让lambda表达式更加稳定，更加快速，需要更少的资源，避免类型截断的问题，变量声明引起的歧义：

```
std::vector<int> v;
unsigned sz = v.size(); //在32位下运行良好，因为此时size()返回的size_type是32位的，unsigned也是32位的，但是在64位上就不行了，size_type会变成64位，而unsigned仍然是32位
auto     sz = v.size(); //在64位机器上仍然表现良好
```

# 6. auto推导若非己愿，使用显式类型初始化惯用法

```
    std::vector<bool> features(const Widget& w);
    Widget w;
    auto highPriority = features(w)[5]

    processWidget(w, highPriority); // 未定义的行为，因为这个时候highPriority已经不是bool类型的了，这个时候返回的是一个std::vector<bool>::reference对象（内嵌在std::vector<bool>中的对象）
如果用：

    bool highPriority = features(w)[5];的时候，因为编译器看到bool，所以会发生隐式转换，将reference转换成bool类型
当然也有强制变成bool 的方法：

    auto highPriority = static_cast<bool>(features(w)[5]);
```

