
#include <iostream>
#include <thread>

void hello()
{
    for(int i=0; i<5; i++)
    {
        std::cout << "Hello Concurrent world\n"<< std::endl;
    }
}

int main()
{
    std::thread t(hello);
    t.join();
    return 0;
}
