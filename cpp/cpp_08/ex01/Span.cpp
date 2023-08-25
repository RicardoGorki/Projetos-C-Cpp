#include "Span.hpp"

Span::Span()
{
	throw std::runtime_error("Only with parameters unsigned int");
};

Span::Span(unsigned int unValue) : _size(unValue)
{
	if (_size != 0)
		std::multiset<int> _array[_size];
};

Span::Span(Span const &other) : _size(other._size), _array(other._array){};

Span &Span::operator=(Span const &other)
{
	_size = other._size;
	_array = other._array;
	return (*this);
};

void Span::addNumber(int nValue)
{
	if (_array.size() < _size)
		_array.insert(nValue);
	else
		throw std::logic_error("maximum size reached!");
};

void Span::generator(Span &other)
{
	if (other._size < 10000)
	{
		std::srand(std::time(NULL));
		for (unsigned int i = 0; i < other._size; i++)
		{
			int random = std::rand() % 1000000;
			other.addNumber(random);
		}
	}
	else
		throw std::logic_error("Put a value below 10000");
}

unsigned int Span::shortestSpan()
{
	if (_array.size() > 1)
	{
		std::multiset<int>::iterator it = _array.begin();
		std::multiset<int>::iterator next = it;
		++next;
		int count = *it;
		for (; next != _array.end(); ++it, ++next)
		{
			if (*next - *it < count)
				count = *next - *it;
		}
		return (count);
	}
	else
		throw std::logic_error("Can't find it");
};

unsigned int Span::longestSpan()
{
	if (_array.size() > 1)
	{
		std::multiset<int>::iterator it = _array.begin();
		std::multiset<int>::iterator last = _array.end();
		--last;
		return (*last - *it);
	}
	else
		throw std::logic_error("Can't find it");
};

Span::~Span(){};
