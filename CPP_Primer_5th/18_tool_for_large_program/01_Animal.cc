/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 09:35:43
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 09:37:13
 * @Description: file content
 */

#include "Animal.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

// operations that take references to base classes of type Panda
void print(const Bear&)
{
	cout << "print(const Bear&)" << std::endl;

}
void highlight(const Endangered&)
{
	cout << "highlight(const Endangered&)" << std::endl;
}

ostream& operator<<(ostream &os, const ZooAnimal&)
{
	return os << "ZooAnimal output operator" << endl;
}

int main()
{
	Panda ying_yang("ying_yang");
	print(ying_yang);     // passes Panda to a reference to Bear
	highlight(ying_yang); // passes Panda to a reference to Endangered
	cout << ying_yang << endl; // passes Panda to a reference to ZooAnimal

    Panda ling_ling = ying_yang;    // uses the copy constructor

	return 0;
}
