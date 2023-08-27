#include "PmergeMe.hpp"

int verifyContent(std::string content)
{
	for (size_t i = 0; i < content.length(); i++)
	{
		if (!isdigit(content[i]))
			return (1);
	}
	return (0);
}

void printDeque(std::deque<int> myDeque)
{
	std::deque<int>::iterator it;
	for (it = myDeque.begin(); it != myDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printList(std::list<int> myList)
{
	std::list<int>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void goMergeDeque(std::deque<int> myDeque)
{
	clock_t start = clock();

	for (int i = 0; i <= 100000; ++i)
	{

    }


	clock_t end = clock();
	double time_taken = (end - start) * CLOCKS_PER_SEC / 1000000.0 ;
	std::cout << "After:\t";
	printDeque(myDeque);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << myDeque.size() << " elements with std::[deque] : " << time_taken << " us " <<std::endl;
};

void goMergeList(std::list<int> myList)
{
	clock_t start = clock();




	clock_t end = clock();
	double time_taken = (end - start) * CLOCKS_PER_SEC / 1000000.0 ;
	std::cout << "After:\t";
	printList(myList);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << myList.size() << " elements with std::[list] : " << time_taken << " us " <<std::endl;
};
