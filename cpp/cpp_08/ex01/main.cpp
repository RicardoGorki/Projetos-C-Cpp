#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(4);
		//sp.generator(sp);
		/*std::vector<int> newVector;
		newVector.push_back(5);
		newVector.push_back(15);
		newVector.push_back(25);
		newVector.push_back(55);
		sp.rangeGenerator(newVector.begin(), newVector.end());*/
		sp.addNumber(5);
		sp.addNumber(15);
		sp.addNumber(25);
		sp.addNumber(55);
		//sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
