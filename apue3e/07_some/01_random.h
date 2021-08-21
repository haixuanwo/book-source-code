/**
 * @author clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-21
 */
#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    Random();
    bool set_range(int min, int max);
    int get_random();
    ~Random();
private:
    int m_min;
    int m_max;
};

#endif

