/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 10:36:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 10:39:39
 * @Description: file content
 */

#ifdef _WIN32
#include <Windows.h>
#elif defined __GNUC__
#include <pthread.h>
#include <sched.h>
#include <string.h>
#endif

#include <iostream>
#include <thread>

void affinity_cpu(std::thread::native_handle_type t, int cpu_id) {
#ifdef _WIN32
  if (!SetThreadAffinityMask(t, 1ll << cpu_id)) {
    std::cerr << "fail to affinity" << GetLastError() << std::endl;
  }
#elif defined __GNUC__
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);
  CPU_SET(cpu_id, &cpu_set);
  int res = pthread_setaffinity_np(t, sizeof(cpu_set), &cpu_set);
  if (res != 0) {
    errno = res;
    std::cerr << "fail to affinity" << strerror(errno) << std::endl;
  }
#endif
}

void affinity_cpu_on_current_thread(int cpu_id) {
#ifdef _WIN32
  if (!SetThreadAffinityMask(GetCurrentThread(), 1ll << cpu_id)) {
    std::cerr << "fail to affinity" << GetLastError() << std::endl;
  }
#elif defined __GNUC__
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);
  CPU_SET(cpu_id, &cpu_set);
  int res = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set), &cpu_set);
  if (res != 0) {
    errno = res;
    std::cerr << "fail to affinity" << strerror(errno) << std::endl;
  }
#endif
}

void f() { affinity_cpu_on_current_thread(0);
    while (1)
    {
        
    }
}

int main() {
  std::thread t1{[] {
    while (1)
    {

    }
  }};

  affinity_cpu(t1.native_handle(), 1);
  std::thread t2{f};
  t1.join();
  t2.join();
}
