/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 19:35:22
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-11 19:36:26
 * @Description: file content
 */

/*
条款2: 尽量以const、enum、inline替换#define
使用预处理指令（#define）定义常量和宏可能导致调试困难，因为预处理器只是
简单的文本替换，并不检查类型等。相反，使用const关键字可以确保类型安全，
使用enum和inline可以替代宏，提供更清晰、更安全的代码。
*/

// bad
#define ASPECT_RATIO 1.653

// good
const double AspectRatio = 1.653;

enum Color { RED, GREEN, BLUE };

template<typename T>
inline T max(T a, T b) { return a > b? a : b; }
