/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 10:05:52
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 10:06:58
 * @Description: file content
 */

#include <string>
#include <vector>
#include <iostream>

struct Base1
{
    void print(int) const     // public by default
	{
        std::cout << "Base1::print(int) " << ival << std::endl;
    }

protected:
    int ival = 1;
};

struct Base2
{
    void print(double) const        // public by default
	{
        std::cout << "Base2::print(double) " << ival << std::endl;
    }

protected:
    int ival = 2;
};

struct Derived : public Base1
{
    void print(std::string) const   // public by default
	{
        std::cout << "Derived::print(string) " << ival << std::endl;
    }

protected:
	int ival = 3;
};

struct MI : public Derived, public Base2
{
    void print(std::vector<double>) // public by default
	{
        std::cout << "MI::print(int(vector<double>) "
			        << ival << std::endl;
    }

protected:
    int ival = 4;
};

int main()
{
	MI obj;
	obj.Base1::print(0);
	obj.Base2::print(3.14);
	obj.Derived::print("hi");
	obj.print(std::vector<double>());

	return 0;
}
