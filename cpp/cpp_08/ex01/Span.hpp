#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

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
};

#endif
