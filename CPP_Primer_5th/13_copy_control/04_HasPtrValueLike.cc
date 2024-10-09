/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-20 11:20:59
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-20 11:25:12
 * @Description: file content
 */

#include <string>

// value-like implementation of HasPtr
class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);

public:
    HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) { }

	// each HasPtr  has its own copy of the string to which ps points
    HasPtr(const HasPtr &p):
		ps(new std::string(*p.ps)), i(p.i) { }

	HasPtr& operator=(const HasPtr &);

	~HasPtr() { delete ps; }
private:
    std::string *ps;
    int    i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

using std::string;
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;
    return ret;
}

int main()
{
    HasPtr h("hi mom!");
    f(h);
}
