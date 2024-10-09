/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-19 12:52:45
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-19 12:52:49
 * @Description: file content
 */

#include <memory>
using std::make_shared;
using std::weak_ptr;
using std::shared_ptr;

int main()
{
    auto p = make_shared<int>(42);

	weak_ptr<int> wp(p);  // wp weakly shares with p; use count in p is unchanged

	p.reset(); // assuming p.unique() was true, the int is deleted

	if (shared_ptr<int> np = wp.lock()) { // true if np is not null
		// inside the if, np shares its object with p
	}
}
