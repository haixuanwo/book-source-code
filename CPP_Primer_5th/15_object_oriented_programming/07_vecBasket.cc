/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-13 23:32:41
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 10:13:24
 * @Description: file content
 */

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr; using std::make_shared;

#include "Quote.h"

int main ()
{
    Quote base("0-201-82470-1", 50);
	Bulk_quote bulk("0-201-54848-8", 50, 10, .25);

	// ok: but probably not what is wanted---
	//     the objects in basket have no derived members
	vector<Quote> basket;
	basket.push_back(Quote("0-201-82470-1", 50));

	// ok, but copies only the Quote part of the object into basket
	basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));

	// calls version defined by Quote, prints 750, i.e., 15 * $50
	cout << basket.back().net_price(15) << endl;

	// better approach---store shared_ptrs
	vector<shared_ptr<Quote>> basket2;

	basket2.push_back(make_shared<Quote>("0-201-82470-1", 50));
	basket2.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));

	// calls the version defined by Quote;
	// prints 562.5, i.e., 15 * $50 less the discount
	cout << basket2.back()->net_price(15) << endl;

	return 0;
}
