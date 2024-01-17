

#include <iostream>
#include <cstddef>
using std::size_t;

using std::cout;
using std::endl;

#include "Quote.h"

int main()
{
    Quote basic("0-201-54848-8", 45);
	Bulk_quote bulk("0-201-82470-1", 45, 3, .15);

	// basic has type Quote; bulk has type Bulk_quote
	print_total(cout, basic, 20); // calls Quote version of net_price
	print_total(cout, bulk, 20);  // calls Bulk_quote version of net_price
	Quote base("0-201-82470-1", 50);
	Bulk_quote derived("0-201-82470-1", 50, 5, .19);
	cout << derived.net_price(20); // calls Bulk_quote::net_price
	cout << endl;

	base = derived;        // copies the Quote part of derived into base
	cout << base.net_price(20);    // calls Quote::net_price
	cout << endl;

	Quote &item = derived; // dynamic and static types of item differ
	cout << item.net_price(20);    // calls Bulk_quote::net_price

	item.isbn();           // isbn is not virtual, calls Bulk::isbn
	cout << endl;

	return 0;
}