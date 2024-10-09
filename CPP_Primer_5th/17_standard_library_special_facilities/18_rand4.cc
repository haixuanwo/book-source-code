/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:31:14
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:31:19
 * @Description: file content
 */

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

#include <algorithm>
using std::max_element;

int main()
{
	default_random_engine e;  // generates unsigned random integers
	// uniformly distributed from 0 to 1 inclusive
	uniform_real_distribution<double> u(0,1);
	for (size_t i = 0; i < 10; ++i)
    	cout << u(e) << " ";
	cout << endl;

	// empty <> signify we want to use the default result type
	uniform_real_distribution<> u2(0,1); // generates double by default
	default_random_engine e2;
	for (size_t i = 0; i < 10; ++i)
    	cout << u2(e2) << " ";  // should generate the same sequence
	cout << endl;

	default_random_engine e3;
	// uniformly distributed from 0 to 9 inclusive
	uniform_int_distribution<unsigned> u3(0,9);
	for (size_t i = 0; i < 100; ++i)
    	cout << u3(e3) << ((i != 99)? " ": "");
	cout << endl;

	return 0;
}
