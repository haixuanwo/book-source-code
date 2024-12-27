#include <algorithm>
#include <thread>
#include <iostream>

void show(int a)
{
	std::cout << a+1 << std::endl;
}



int main()
{
	std::cout << std::thread::hardware_concurrency() << std::endl;


	std::vector<int> data;
	for (int i=0; i<100; i++)
	{
		data.push_back(i);
	}

	std::for_each(data.begin(), data.end(), show);
  std::cout << "size: " << std::distance(data.begin(), data.end()) << std::endl;

	return 0;
}

