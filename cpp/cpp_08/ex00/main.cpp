#include "easyfind.hpp"

int main()
{
	try
	{
		std::cout << "Test: 1" << std::endl;
		std::cout << "Values: 1,2,5,3,10,15,17" << std::endl;
		std::cout << "Try find: 15" << std::endl;
		std::vector<int> x;
		x.push_back(1);
		x.push_back(2);
		x.push_back(5);
		x.push_back(3);
		x.push_back(10);
		x.push_back(15);
		x.push_back(17);
		::easyfind<std::vector<int> >(x, 15);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Test: 2" << std::endl;
		std::cout << "Values: 1,2,5,3,10,15,17" << std::endl;
		std::cout << "Try find: 18" << std::endl;
		std::vector<int> x;
		x.push_back(1);
		x.push_back(2);
		x.push_back(5);
		x.push_back(3);
		x.push_back(10);
		x.push_back(15);
		x.push_back(17);
		::easyfind<std::vector<int> >(x, 18);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
