/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 17:32:55
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:32:59
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

// almost surely the wrong way to generate a vector of random integers
// output from this function will be the same 100 numbers on every call!
vector<unsigned> bad_randVec()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0,9);
	vector<unsigned> ret;

	for (size_t i = 0; i < 100; ++i)
    	ret.push_back(u(e));

	return ret;
}

// returns a vector of 100 uniformly distributed random numbers
vector<unsigned> good_randVec()
{
	// because engines and distributions retain state, they usually should be
	// defined as static so that new numbers are generated on each call
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0,9);
	vector<unsigned> ret;

	for (size_t i = 0; i < 100; ++i)
    	ret.push_back(u(e));
        
	return ret;
}

int main()
{
	vector<unsigned> v1(bad_randVec());
	vector<unsigned> v2(bad_randVec());

	// will print equal
	cout << ((v1 == v2) ? "equal" : "not equal") << endl;

	// very unlikely to print equal
	if (good_randVec() == good_randVec())
		cout << "equal!" << endl;
	else
		cout << "not equal" << endl;
}
