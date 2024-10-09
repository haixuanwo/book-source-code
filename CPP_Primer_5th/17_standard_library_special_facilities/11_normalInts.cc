/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:12:02
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:12:06
 * @Description: file content
 */

#include <string>
using std::string;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::normal_distribution;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::max_element;

#include <numeric>
using std::accumulate;

#include <cmath>
using std::lround;

#include <cstddef>
using std::size_t;

int main()
{
	default_random_engine e;        // generates random integers
	normal_distribution<> n(4,1.5); // mean 4, standard deviation 1.5
	vector<unsigned> vals(9);       // nine elements each 0

	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e));  // round to the nearest integer
		if (v < vals.size())        // if this result is in range
			++vals[v];              // count how often each number appears
	}

	int sum = accumulate(vals.begin(), vals.end(), 0);

	if (sum != 200)
		cout << "discarded " << 200 - sum << " results" << endl;

	for (size_t j = 0; j != vals.size(); ++j)
		cout << j << ": " << string(vals[j], '*') << endl;

	return 0;
}

