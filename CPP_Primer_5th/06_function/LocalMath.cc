/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 13:50:51
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 13:53:01
 * @Description: file content
 */

#include "LocalMath.h"

int gcd(int v1, int v2)
{
    while (v2) {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;
    }
    return v1;
}

int fact(int val) // 阶乘
{
	int ret = 1; // local variable to hold the result as we calculate it
	while (val > 1)
		ret *= val--;  // assign ret * val to ret and decrement val
	return ret;        // return the result
}

int factorial(int val)  // 阶乘
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
