/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-12 09:28:14
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-12 11:37:16
 * @Description: file content
 */

/*
条款27：尽量少做转型动作
在C++中，转型可能会隐藏类型错误，降低程序的安全性。应当尽量避免使用C风格的转型，
转而使用C++的四种类型转型（static_cast、dynamic_cast、const_cast、reinterpret_cast），
它们更加清晰并且各自有明确的用途。
*/

void f(double d)
{
    int i = static_cast<int>(d);  // 使用 static_cast 进行类型转换
    std::cout << "The value of i is: " << i << std::endl;
}
