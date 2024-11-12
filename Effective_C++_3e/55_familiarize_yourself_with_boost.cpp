
/*
条款55：让自己熟悉Boost
Boost库是一个广泛使用的C++库，提供了标准库中缺失的组件，许多Boost库的功能最终成为了C++标准的
一部分。

使用Boost库中的boost::lexical_cast进行类型转换：
*/

#include <boost/lexical_cast.hpp>
#include <iostream>

int main() {
    std::string text = "123";
    int num = boost::lexical_cast<int>(text);
    std::cout << "Converted number: " << num << std::endl;
}
