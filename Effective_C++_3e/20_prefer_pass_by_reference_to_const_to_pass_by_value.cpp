
/*
条款20：宁以 pass-by-reference-to-const 替换 pass-by-value

宁以 pass-by-reference-to-const 替换 pass-by-value
为了避免不必要的对象复制，应优先使用 const 引用传递参数，特别是对于大型对象。
这种方式既可以防止对象被修改，又可以避免复制成本，同时保持函数调用的效率。
*/

class LargeClass {};

void process(const LargeClass& obj) {
    // 处理 obj，不会发生复制
}
