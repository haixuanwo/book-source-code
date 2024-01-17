/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 10:01:18
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 10:01:26
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

namespace primerLib
{
    void compute()
    {
        cout << "primerLib::compute()" << endl;
    }

    void compute(const void *)
	{
        cout << "primerLib::compute(const void *)" << endl;
    }
}

// brings comput() and compute(const void*) into scope
using primerLib::compute;

void compute(int)
{
    cout << "compute(int)" << endl;
}

void compute(double, double = 3.4)
{
    cout << "compute(double, double)" << endl;
}

void compute(char*, char* = 0)
{
    cout << "compute(char*, char*)" << endl;
}

int main()
{
	int i = 42;
	char c = 'a';
	compute(i);  // compute(int)
	compute(c);  // compute(int)
	compute(&i); // primerLib::compute(const void*)
	compute(&c); // compute(char*, char*)
	compute(3.4);// compute(double, double)

	return 0;
}
