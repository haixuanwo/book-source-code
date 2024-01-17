/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-13 15:49:51
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-13 15:51:12
 * @Description: file content
 */

#include "Quote.h"
#include "Basket.h"

#include <cstddef>
using std::size_t;

#include <set>
using std::multiset;

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::endl;
using std::cout;

// debugging routine to check contents in a Basket
void Basket::display(ostream &os) const
{
    os << "Basket size: " << items.size() << endl;

    // print each distinct ISBN in the Basket along with
    // count of how many copies are ordered and what their price will be
    // upper_bound returns an iterator to the next item in the set
    for (auto next_item = items.cbegin();
              next_item != items.cend();
              next_item = items.upper_bound(*next_item))
    {
        // we know there's at least one element with this key in the Basket
        os << (*next_item)->isbn() << " occurs "
           << items.count(*next_item) << " times"
           << " for a price of "
           << (*next_item)->net_price(items.count(*next_item))
           << endl;
    }
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;    // holds the running total

    // iter refers to the first element in a batch of elements with the same ISBN
    // upper_bound returns an iterator to the element just past the end of that batch
    for (auto iter = items.cbegin();
              iter != items.cend();
              iter = items.upper_bound(*iter))
    {
        // we know there's at least one element with this key in the Basket
		// print the line item for this book
        sum += print_total(os, **iter, items.count(*iter));
    }

	os << "Total Sale: " << sum << endl; // print the final overall total
    return sum;
}
