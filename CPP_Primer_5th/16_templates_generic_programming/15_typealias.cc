/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 16:40:06
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 16:43:28
 * @Description: file content
 */

#include "Blob.h"

#include <utility>
using std::pair;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

typedef Blob<string> StrBlob;

template<typename T> using twin = pair<T, T>;
template <typename T> using partNo = pair<T, unsigned>;

int main()
{
	// authors is a pair<string, string>
	twin<string> author("Mark", "Twain");
    cout << author.first << " " << author.second << endl;

	twin<int> win_loss(2, 45);  // win_loss is a pair<int, int>
    cout << win_loss.first << " " << win_loss.second << endl;

	typedef string Vehicle;
	partNo<Vehicle> car("volvo", 242);  // car is a pair<Vehicle, unsigned>
    cout << car.first << " " << car.second << endl;

	return 0;
}

