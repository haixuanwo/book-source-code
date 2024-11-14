
# More Effective C++

## 01 基础议题（Basics）
- 条款1：区别pointers和references
- 条款2：最好使用C++转型操作符
- 条款3：绝对不要以多态方式处理数组
- 条款4：非必要不提供default constructor

## 02 操作符（Operator）
- 条款5：对定制的“类型转换函数”保存警觉
- 条款6：区别increment/decrement操作符的前置（prefix）和后置（postfix）形式
- 条款7：千万不要重载&&和||和，操作符
- 条款8：了解各种不同意义的new和delete操作符

## 03 异常（Exception）
- 条款9：利用destructors避免泄露资源
- 条款10：在constructor内阻止资源泄漏
- 条款11：禁止异常（except）流出destructor之外
- 条款12：了解“抛出一个exception”与“传递一个参数”或“调用一个虚函数”之间的差异
- 条款13：以by reference方式捕获异常
- 条款14：明智运用exception specifications
- 条款15：了解异常处理（exception handling）的性能影响

## 04 效率（Efficiency）
- 条款16：谨记80-20法则
- 条款17：考虑使用lazy evaluation（缓式评估）
- 条款18：分期摊还预期的及计算成本
- 条款19：了解临时对象的来源
- 条款20：协助完成“返回值优化（RVO）”
- 条款21：利用重载技术（overload）避免隐式类型转换
- 条款22：考虑以操作符复合形式（op=）取代其独身形式（op）
- 条款23：考虑使用其他程序库
- 条款24：了解virtual function、multiple inheritance、virtual base class、runtime type identification的成本

## 05 技术（Technique，Idiom, Pattern）
- 条款25：将constructor和non-member function虚化
- 条款26：限制class产生对象数量
- 条款27：要求（或禁止）对象产生与heap中
- 条款28：智能指针
- 条款29：Reference counting（引用计数）
- 条款30：Proxy class（替身类、代理类）
- 条款31：让函数根据一个以上的对象类型来决定如何虚化

## 06 杂项讨论（Miscellany）
- 条款32：在未来时态下发展程序
- 条款33：将非尾端类（non-leaf class）设计为抽象类
- 条款34：如何在同一程序中结合C++和C
- 条款35：让自己习惯于标准C++语言
