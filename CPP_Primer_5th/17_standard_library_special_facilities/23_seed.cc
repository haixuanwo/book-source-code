/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:45:29
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:47:06
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main()
{
	default_random_engine e1;             // uses the default seed
	default_random_engine e2(2147483646); // use the given seed value

	// e3 and e4 will generate the same sequence
	// because they use the same seed
	default_random_engine e3;        // uses the default seed value
	e3.seed(32767);                  // call seed to set a new seed value
	default_random_engine e4(32767); // set the seed value to 32767

    for (size_t i = 0; i != 100; ++i)
    {
		if (e1() == e2())
			cout << "unseeded match at iteration: " << i << endl;

        if (e3() != e4())
			cout << "seeded differs at iteration: " << i << endl;
	}

	return 0;
}
