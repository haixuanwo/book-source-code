
#include <atomic>

/**
 * std::atomic_flag是 C++11 中引入的原子类型，用于实现简单的原子布尔标志，
 * 主要功能是提供一种无锁的、原子的布尔标志操作，常用于多线程环境下的同步和互斥，
 * 以确保在多线程访问共享资源时的正确性和一致性
 */

class spinlock_mutex
{
    std::atomic_flag flag;

public:
    spinlock_mutex() : flag(ATOMIC_FLAG_INIT)
    {

    }

    void lock()
    {
        while(flag.test_and_set(std::memory_order_acquire));
        // 临界区，只有一个线程能进入
    }

    void unlock()
    {
        flag.clear(std::memory_order_release);
        // 清除标志，允许其他线程进入临界区
    }
};
