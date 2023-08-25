#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(15);
		sp.generator(sp);
		/* sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11); */

		/* std::multiset<int>::iterator it;
		for (it = _array.begin(); it != _array.end(); ++it)
        	std::cout << *it << " ";
		std::cout << std::endl; */

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
