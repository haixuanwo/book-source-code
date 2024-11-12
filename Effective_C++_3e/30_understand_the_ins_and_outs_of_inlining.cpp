/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:44:14
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 09:44:17
 * @Description: file content
 */

/*
条款30：透彻了解 inlining 的里里外外
内联函数可以减少函数调用的开销，但过度使用内联可能导致代码膨胀，
影响程序的性能和内存使用。了解何时以及如何使用内联，可以帮助写出更高效的代码。
*/

inline int max(int a, int b)
{
    return a > b ? a : b;  // 简单函数适合内联
}

void example() {
    int m = max(10, 20);  // 使用内联函数
}
