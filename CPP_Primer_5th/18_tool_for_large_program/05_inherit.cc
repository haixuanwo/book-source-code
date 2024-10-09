/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 10:04:04
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 10:04:08
 * @Description: file content
 */

#include <iostream>

namespace NS
{
    class Quote
    {
	public:
		Quote()
        {
            std::cout << "Quote::Quote" << std::endl;
        }
	};

    void display(const Quote&)
	{
        std::cout << "display(const Quote&)" << std::endl;
    }
}

// Bulk_item's base class is declared in namespace NS
class Bulk_item : public NS::Quote
{
public:
	Bulk_item()
    {
        std::cout << "Bulk_item::Bulk_item" << std::endl;
    }
};

int main()
{
    Bulk_item book1;

    display(book1); // calls Quote::display

    return 0;
}
