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

void printDeque(std::deque<int> &myDeque)
{
	std::deque<int>::iterator it;
	for (it = myDeque.begin(); it != myDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printList(std::list<int> &myList)
{
	std::list<int>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void insertionSortDeque(std::deque<int> &myDeque)
{
	for (std::deque<int>::iterator it = myDeque.begin() + 1; it != myDeque.end(); ++it)
	{
		int temp = *it;
		std::deque<int>::iterator j = it - 1;

		while (j >= myDeque.begin() && *j > temp)
		{
			*(j + 1) = *j;
			--j;
		}

		*(j + 1) = temp;
	}
}

void mergeInsertSortDeque(std::deque<int> &myDeque, int left, int right)
{

	if (right - left <= 15)
		insertionSortDeque(myDeque);
	else
	{
		int middle = left + (right - left) / 2;

		mergeInsertSortDeque(myDeque, left, middle);
		mergeInsertSortDeque(myDeque, middle + 1, right);

		mergeDeque(myDeque, left, middle, right);
	}
}

void mergeDeque(std::deque<int> &myDeque, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::deque<int> leftDeque;
	std::deque<int> rightDeque;

	for (int i = 0; i < n1; ++i)
		leftDeque.push_back(myDeque[left + i]);
	for (int j = 0; j < n2; ++j)
		rightDeque.push_back(myDeque[middle + 1 + j]);

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (leftDeque[i] <= rightDeque[j])
		{
			myDeque[k] = leftDeque[i];
			++i;
		}
		else
		{
			myDeque[k] = rightDeque[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		myDeque[k] = leftDeque[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		myDeque[k] = rightDeque[j];
		++j;
		++k;
	}
}

void insertionSortList(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator right)
{
	for (std::list<int>::iterator it = ++left; it != right; ++it)
	{
		int key = *it;
		std::list<int>::iterator j = it;
		--j;

		while (j != left && *j > key)
		{
			std::swap(*j, *(j));
			--j;
		}

		if (*j > key)
		{
			std::swap(*j, *(j));
			myList.insert(j, key);
		}
		else
		{
			myList.insert(j, key);
		}
	}
}

void mergeSortList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
{
	std::list<int> leftList(left, middle);
	std::list<int> rightList(middle, right);

	std::list<int>::iterator i = leftList.begin();
	std::list<int>::iterator j = rightList.begin();
	std::list<int>::iterator k = left;

	while (i != leftList.end() && j != rightList.end())
	{
		if (*i <= *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}

	while (i != leftList.end())
	{
		*k = *i;
		++i;
		++k;
	}

	while (j != rightList.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

void mergeInsertionSortList(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator right)
{
	if (std::distance(left, right) > 1)
	{
		std::list<int>::iterator middle = left;
		std::advance(middle, std::distance(left, right) / 2);

		mergeInsertionSortList(myList, left, middle);
		mergeInsertionSortList(myList, middle, right);
		mergeSortList(left, middle, right);
	}
}

void goMergeList(std::list<int> &myList)
{
	clock_t start = clock();
	mergeInsertionSortList(myList, myList.begin(), myList.end());
	clock_t end = clock();
	double time_taken = (end - start) * CLOCKS_PER_SEC / 1000000.0;
	std::cout << "After:\t";
	printList(myList);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << myList.size() << " elements with std::[list] : " << time_taken << " us " << std::endl;
};

void goMergeDeque(std::deque<int> &myDeque)
{
	clock_t start = clock();
	mergeInsertSortDeque(myDeque, 0, myDeque.size() - 1);
	clock_t end = clock();
	double time_taken = (end - start) * CLOCKS_PER_SEC / 1000000.0;
	std::cout << "After:\t";
	printDeque(myDeque);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << myDeque.size() << " elements with std::[deque] : " << time_taken << " us " << std::endl;
};
