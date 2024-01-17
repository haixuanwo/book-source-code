/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 16:59:56
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 17:00:01
 * @Description: file content
 */

#include <string>
using std::string;

#include <random>
using std::default_random_engine;
using std::bernoulli_distribution;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool play(bool player)
{
    return player;
}

int main()
{
	string resp;
	// distributions and engines have state,
    // they must be defined outside the loop!
	default_random_engine e;

	// 50/50 odds by default
	bernoulli_distribution b(0.55); // give the house a slight edge

	do
    {
		bool first = b(e);    // if true, the program will go first
		cout << (first ? "We go first"
	                   : "You get to go first") << endl;
		// play the game passing the indicator of who goes first
		cout << ((play(first)) ? "sorry, you lost"
	                           : "congrats, you won") << endl;
		cout << "play again? Enter 'yes' or 'no'" << endl;
	} while (cin >> resp && resp[0] == 'y');

	return 0;
}

