/**
 * @author clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-08-21
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "01_random.h"

Random::Random()
{
    m_min = 0;
    m_max = 0;
}

bool Random::set_range(int min, int max)
{
    if (min < 0 || max < 0 || min > max)
        return false;

    m_min = min;
    m_max = max > RAND_MAX ? RAND_MAX : max;
    return true;
}

int Random::get_random()
{
    // 设置随机数种子
    srand(time(nullptr));

    // 返回 range 0 to RAND_MAX
    int num = rand();

    // 取范围
    if (m_max > 0 && m_min < m_max)
    {
        // printf("min[%d] ~ max[%d]\n", m_min, m_max);
        num = (m_min + num%(m_max - m_min));
    }

    return num;
}

Random::~Random()
{

}

