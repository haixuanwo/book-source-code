/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:22:15
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:31:09
 * @Description: file content
 */

/*
条款18：让接口容易被正确使用，不易被误用

设计接口时，应使其容易正确使用且难以错误使用。
使用类型安全、明确的参数和返回类型，
通过编译时检查和运行时断言来防止错误的使用。
*/

class Date {
public:
    Date(int year, int month, int day) {
        // 添加断言来验证日期的有效性
        assert(year > 1900 && month > 0 && month < 13 && day > 0 && day < 32);
        // 初始化日期
    }
};

