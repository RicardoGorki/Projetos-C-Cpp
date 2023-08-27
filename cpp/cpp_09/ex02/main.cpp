#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			if (verifyContent(argv[i]))
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
		}
		std::deque<int> myDeque;
		std::list<int> myList;
		for (int i = 1; i < argc; i++)
		{
			myDeque.push_back(atoi(argv[i]));
			myList.push_back(atoi(argv[i]));
		}
		std::cout << std::endl;
		std::cout << "____.::Deque::.____" << std::endl;
		std::cout << "Before:\t";
		printDeque(myDeque);
		// sort deque;
		goMergeDeque(myDeque);
		std::cout << std::endl;

		std::cout << "____.::List::.____" << std::endl;
		std::cout << "Before:\t";
		printList(myList);
		// sort list;
		goMergeList(myList);

		std::cout << std::endl;
	}
	else
		std::cout << "Error" << std::endl;
	return 0;
}
