/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 18:02:20
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-16 18:02:24
 * @Description: file content
 */

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <tuple>
using std::tuple;
using std::get;
using std::tuple_size;
using std::tuple_element;
using std::make_tuple;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// tuple that represents a bookstore transaction:
	// ISBN, count, price per book
	auto item = make_tuple("0-999-78345-X", 3, 20.00);
	auto book = get<0>(item);      // returns the first member of item
	auto cnt = get<1>(item);       // returns the second member of item
	auto price = get<2>(item)/cnt; // returns the last member of item
	get<2>(item) *= 0.8;           // apply 20% discount

	cout << book << " " << cnt << " " << price << endl;

	typedef decltype(item) trans; // trans is the type of item

	// returns the number of members in object's of type trans
	size_t sz = tuple_size<trans>::value;  // returns 3

	// cnt has the same type as the second member in item
	tuple_element<1, trans>::type cnt2 = get<1>(item); // cnt is an int
	tuple_element<0, trans>::type book2 = get<0>(item);
	tuple_element<2, trans>::type price2 = get<2>(item);
	cout << tuple_size<trans>::value << endl;

	cout << book2 << " " << cnt2 << " " << price2 << endl;

	tuple<size_t, size_t, size_t> threeD;  // all three members set to 0
	tuple<string, vector<double>, int, list<int>>
	    someVal("constants", {3.14, 2.718}, 42, {0,1,2,3,4,5});

	return 0;
}
