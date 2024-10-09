/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:28:05
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:29:18
 * @Description: file content
 */

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::normal_distribution;

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

#include <numeric>
using std::accumulate;

#include <cmath>
using std::lround;

int main()
{
	vector<int> vals(32);     // preallocate so each element is 0
	default_random_engine e;  // generates numbers
	uniform_int_distribution<unsigned> u(0,31); // inclusive range

	for (size_t i = 0; i != 100; ++i)
		++vals[u(e)];         // count how often each number appears

    int m = *max_element(vals.begin(), vals.end());
	for (int i = m; i != 0; --i)
    {
		for (size_t j = 0; j != vals.size(); ++j)
		{
            if (vals[j] > i-1)
            {
                cout << "* ";
            }
			else
            {
                cout << "  ";
            }
        }
        cout << endl;
	}

	vector<int> vals2(32);     // preallocate so each element 0 value
	default_random_engine e2;  // restart the sequence
	normal_distribution<> n(15,5); // mean 15, standard deviation 5
	for (size_t i = 0; i != 100; ++i)
    {
		size_t v = lround(n(e));
		if (v < vals.size())
			++vals[v];         // count how often each number appears
		else
			cout << "discarding: " << v << " ";
	}
	cout << endl;

	cout << std::accumulate(vals.begin(), vals.end(), 0) << endl;
	m = *max_element(vals.begin(), vals.end());
	for (int i = m; i != 0; --i)
    {
		for (size_t j = 0; j != vals.size(); ++j)
        {
			if (vals[j] > i-1)
            {
                cout << "* ";
            }
			else
            {
                cout << "  ";
            }
        }
        cout << endl;
	}

	return 0;
}
