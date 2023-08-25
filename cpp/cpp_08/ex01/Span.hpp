#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>

class Span
{
private:
	unsigned int _size;
	std::multiset<int> _array;

public:
	Span();
	~Span();
	Span(Span const &other);
	Span &operator=(Span const &other);
	Span(unsigned int unValue);
	void addNumber(int nValue);
	void generator(Span &other);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template<typename Iterator>
	void rangeGenerator(Iterator rangeBegin, Iterator rangeEnd)
	{
		for (Iterator range = rangeBegin; range != rangeEnd; range++ )
		{
			addNumber(*range);
		}
	}
};

#endif
