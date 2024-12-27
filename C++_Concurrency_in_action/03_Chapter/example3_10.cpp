/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 15:58:32
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 16:00:05
 * @Description: file content
 */
#include <mutex>
#include <iostream>

class Y
{
private:
    int some_detail;
    mutable std::mutex m;

    int get_detail() const
    {
        std::lock_guard<std::mutex> lock_a(m);
        return some_detail;
    }

public:
    Y(int sd):some_detail(sd){}

    friend bool operator==(Y const& lhs, Y const& rhs)
    {
        if(&lhs==&rhs)
            return true;

        int const lhs_value=lhs.get_detail();
        int const rhs_value=rhs.get_detail();
        return lhs_value==rhs_value;
    }
};

int main()
{
    Y y1(10);
    Y y2(10);
    Y y3(20);

    if(y1==y2)
        std::cout<<"y1 and y2 are equal"<<std::endl;
    else
        std::cout<<"y1 and y2 are not equal"<<std::endl;

    if(y1==y3)
        std::cout<<"y1 and y3 are equal"<<std::endl;
    else
        std::cout<<"y1 and y3 are not equal"<<std::endl;

    return 0;
}
