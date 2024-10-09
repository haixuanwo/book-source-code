/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-19 12:42:54
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-19 12:44:11
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::uninitialized_copy;
using std::allocator;
using std::uninitialized_fill_n;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};

	allocator<int> alloc;

	// allocate twice as many elements as vi holds
	auto p = alloc.allocate(vi.size() * 2);

    // construct elements starting at p as copies of elements in vi
	auto q = uninitialized_copy(vi.begin(), vi.end(), p);

	// initialize the remaining elements to 42
	uninitialized_fill_n(q, vi.size(), 42);

	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(p + i) << " ";
	cout << endl;

	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(q + i) << " ";
	cout << endl;

	alloc.deallocate(p, vi.size());
}
