/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-11 20:05:36
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:29:56
 * @Description: file content
 */

/*
条款16：成对使用 new 和 delete 时要采取相同形式

在C++中，使用new分配内存时，应确保与之对应的delete使用相同的形式。
如果使用 new[] 分配了一个数组，则应使用 delete[] 来释放；如果使用
new分配了一个单一对象，则应使用delete 来释放。这是因为 new[] 和 delete[]
在内部处理数组构造和析构时与单个对象的构造和析构处理有所不同。
*/

int main() {
    int* array = new int[10];  // 使用 new[] 分配数组
    delete[] array;            // 使用 delete[] 释放数组

    int* single = new int;     // 使用 new 分配单个对象
    delete single;             // 使用 delete 释放单个对象
}
