/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-20 11:35:46
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-20 11:43:34
 * @Description: file content
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

struct numbered {
	static size_t sn;
	numbered() : mysn(sn++)
    {
        std::cout <<__func__<<__LINE__<<" sn: "<<sn<<" mysn: "<<mysn<<std::endl;
    }

	numbered(const numbered &) : mysn(sn++)
    {
        std::cout <<__func__<<__LINE__<<" sn: "<<sn<<" mysn: "<<mysn<<std::endl;
    }

	numbered &operator=(const numbered &)
    {
        std::cout <<__func__<<__LINE__<<" sn: "<<sn<<" mysn: "<<mysn<<std::endl;
        return *this;
    }

	size_t mysn;
};

size_t numbered::sn = 0;

void f (numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;

	f(a);
    f(b);
    f(c);
}
