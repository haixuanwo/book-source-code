/*
 * @Author: Clark (haixuanwoTxh@gmail.com)
 * @Date: 2021-10-26 10:51:10
 * @LastEditTime: 2021-10-26 11:48:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /book-source-code/C++_Ruminations/05_chap_surrogate.cpp
 */

#include <iostream>
#include <vector>

/**
 * @brief 交通工具抽象类
 */
class Vehicle{
public:
    virtual double get_weight() const = 0;
    virtual void start() = 0;
    virtual Vehicle *copy() const = 0;

protected:
    double weight;
};

/**
 * @brief 汽车类
 */
class Automobile :public Vehicle{
public:
    Automobile()
    {
        weight = 0;
    }

    Automobile(int _weight)
    {
        weight = _weight;
    }

    double get_weight() const
    {
        return weight;
    }

    void start()
    {
        std::cout<<"Automobile start"<<std::endl;
    }

    Vehicle *copy() const
    {
        return new Automobile(*this);
    }
};

/**
 * @brief 卡车类
 */
class Truck :public Vehicle{
public:
    Truck()
    {
        weight = 0;
    }

    Truck(int _weight)
    {
        weight = _weight;
    }

    double get_weight() const
    {
        return weight;
    }

    void start()
    {
        std::cout<<"Truck start"<<std::endl;
    }

    Vehicle *copy() const
    {
        return new Truck(*this);
    }
};

/**
 * @brief 交通工具代理类
 */
class VehicleSurrogate{
public:
    VehicleSurrogate():vp(0)
    {

    }

    VehicleSurrogate(const Vehicle &v):vp(v.copy())
    {

    }

    ~VehicleSurrogate()
    {
        delete vp;
    }

    VehicleSurrogate(const VehicleSurrogate& v):vp(v.vp ? v.vp->copy() : 0)
    {

    }

    VehicleSurrogate& operator=(const VehicleSurrogate &v)
    {
        if (this != &v){
            delete vp;
            vp = (v.vp ? v.vp->copy() : 0);
        }
        return *this;
    }

    double get_weight() const
    {
        return vp->get_weight();
    }

    void start()
    {
        vp->start();
    }

private:
    Vehicle *vp;
};

/**
 * @brief 显示代理中所有的交通工具
 *
 * @param V 代理对象容器
 */
void show_Vehicle(std::vector<VehicleSurrogate> V)
{
    for (VehicleSurrogate v : V)
    {
        v.start();
        std::cout<<"weight: "<<v.get_weight()<<std::endl;
    }
}

int main(int argc, char *argv[])
{
    int num_vehicles = 0;

    std::vector<VehicleSurrogate> V;
    VehicleSurrogate surrogate;


    surrogate = Automobile(100);
    V.push_back(surrogate);

    surrogate = Truck(200);
    V.push_back(surrogate);

    surrogate = Automobile(300);
    V.push_back(surrogate);

    surrogate = Truck(400);
    V.push_back(surrogate);

    show_Vehicle(V);

    return 0;
}
