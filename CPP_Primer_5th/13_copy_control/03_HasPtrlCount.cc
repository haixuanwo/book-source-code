/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-20 11:06:08
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-20 11:18:51
 * @Description: file content
 */

#include <string>
#include <cstddef>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1))
    {

    }

    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use)
    {
        ++*use;
    }

    HasPtr& operator=(const HasPtr&);

    ~HasPtr();

    HasPtr(HasPtr &&p): ps(p.ps), i(p.i), use(p.use)
    {
        p.ps = 0;
        p.use = 0;
    }

    HasPtr &operator=(HasPtr&&);

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(HasPtr &&rhs)
{
    if (this != &rhs)
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }

        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        ps = 0;
        use = 0;
    }

    return *this;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    --*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }

    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

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
    HasPtr h2 = h;
}
